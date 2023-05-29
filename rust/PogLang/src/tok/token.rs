use super::tokentype::*;
use std::collections::VecDeque;

#[derive(Debug, Clone)]
pub struct Token {
    pub type_token: TokenType,
    pub id: String,
}

impl Token {
    fn new(type_token: TokenType, id: String) -> Self {
        Self { type_token, id }
    }

    pub fn into_token(word: &str, tokens: &mut VecDeque<Token>) -> bool {
        let mut veri = true;
        if let Some(type_token) = TokenType::is_literal(word) {
            tokens.push_back(Token::new(type_token, word.to_string()));
        } else if let Some(type_token) = TokenType::is_key_word(word) {
            tokens.push_back(Token::new(type_token, word.to_string()));
        } else if let Some(type_token) = TokenType::is_identifier(word) {
            tokens.push_back(Token::new(type_token, word.to_string()));
        } else if let Some(type_token) = TokenType::is_left_bracket(word) {
            tokens.push_back(Token::new(type_token, word.to_string()));
        } else if let Some(type_token) = TokenType::is_right_bracket(word) {
            tokens.push_back(Token::new(type_token, word.to_string()));
        } else {
            veri = false;
        }

        veri
    }

    pub fn into_complex_token(word: &str, tokens: &mut VecDeque<Token>, sep: &char) -> bool {
        let mut buffer = String::with_capacity(word.len());
        let mut veri = true;
        for ch in word.chars() {
            if ch == *sep {
                print!("{}", sep);
                veri = Token::into_token(buffer.as_str(), tokens);
                veri = Token::into_token(sep.to_string().as_str(), tokens);
                buffer.clear();
            } else {
                buffer.push(ch);
            }
        }

        veri
    }
}
