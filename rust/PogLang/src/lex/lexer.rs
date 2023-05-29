use crate::tok::token::Token;
use std::{collections::VecDeque, fmt};

const FUCKERS: [char; 8] = ['+', '-', '*', '/', '(', ')', '{', '}'];

#[derive(Debug, Clone)]
pub struct Lexer {
    cur_line: usize,
    cur_col: usize,
    token_list: VecDeque<Token>,
}
impl fmt::Display for Lexer {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        let mut list = String::new();
        for token in &self.token_list {
            list.push_str(format!("\n{:#?}", token).as_str());
        }
        write!(f, "Error: {}", list)
    }
}

impl Lexer {
    pub fn new() -> Self {
        Self {
            cur_line: 0,
            cur_col: 0,
            token_list: VecDeque::new(),
        }
    }

    fn try_complex_token(word: &str, tokens: &mut VecDeque<Token>) -> bool {
        let mut veri = true;

        for ch in &FUCKERS {
            veri = Token::into_complex_token(word, tokens, &ch);
            if !veri {
                break;
            }
        }
        veri
    }

    pub fn tokenizer(&mut self, pog_file: &str) {
        let mut buffer = String::new();
        let mut veri;

        for ch in pog_file.chars() {
            match ch {
                ' ' => {
                    if !buffer.is_empty() {
                        veri = Token::into_token(&buffer, &mut self.token_list);
                        if !veri {
                            veri = Lexer::try_complex_token(&buffer, &mut self.token_list);
                            if !veri {
                                break;
                            }
                        }
                        buffer.clear();
                    }

                    self.cur_col += 1;
                }

                '\n' => {
                    if !buffer.is_empty() {
                        veri = Token::into_token(&buffer, &mut self.token_list);
                        if !veri {
                            veri = Lexer::try_complex_token(&buffer, &mut self.token_list);
                            if !veri {
                                break;
                            }
                        }
                        buffer.clear();
                    }

                    self.cur_line += 1;
                }

                _ => {
                    buffer.push(ch);
                    self.cur_col += 1;
                }
            }
        }
    }
}
