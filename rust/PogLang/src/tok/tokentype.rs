use regex::RegexSet;

#[derive(Debug, PartialEq, Clone)]
pub enum TokenType {
    Lit(Literal),
    Op(Operator),
    LeftBracket(char),
    RightBracket(char),
    KeyWord,
    Identifier,
}

impl TokenType {
    pub fn is_left_bracket(word: &str) -> Option<TokenType> {
        if word == "(" {
            Some(TokenType::LeftBracket('('))
        } else if word == "{" {
            Some(TokenType::LeftBracket('{'))
        } else {
            None
        }
    }

    pub fn is_right_bracket(word: &str) -> Option<TokenType> {
        if word == ")" {
            Some(TokenType::LeftBracket(')'))
        } else if word == "}" {
            Some(TokenType::LeftBracket('}'))
        } else {
            None
        }
    }
    pub fn is_identifier(word: &str) -> Option<TokenType> {
        let mut chars: Vec<char> = word.chars().collect();
        let mut i = 1;
        let len = chars.len();
        let mut veri = true;

        match chars.get(1).unwrap().to_owned() {
            'a'..='z' | 'A'..='Z' => {
                chars.remove(i);
                while !chars.is_empty() && veri {
                    match chars.get(i).unwrap().to_owned() {
                        'a'..='z' | 'A'..='Z' | '0'..='9' => {
                            veri = true;
                        }
                        _ => {
                            veri = false;
                        }
                    }
                    i += 1;
                }
                if i == len {
                    Some(TokenType::Identifier)
                } else {
                    None
                }
            }
            _ => None,
        }
    }

    pub fn is_key_word(word: &str) -> Option<TokenType> {
        let reg_key_word = RegexSet::new(&[
            r"while", r"if", r"else", r"fn", r"do", r"for", r"return", r"->", r";",
        ])
        .unwrap();

        if reg_key_word.is_match(word) {
            return Some(TokenType::KeyWord);
        } else {
            return None;
        }
    }

    pub fn is_operator(word: &str) -> Option<TokenType> {
        match word {
            "+" => Some(TokenType::Op(Operator::Plus)),
            "-" => Some(TokenType::Op(Operator::Minus)),
            "*" => Some(TokenType::Op(Operator::Multiply)),
            "/" => Some(TokenType::Op(Operator::Divide)),
            "<" => Some(TokenType::Op(Operator::LessThan)),
            "<=" => Some(TokenType::Op(Operator::LessThanOrEqual)),
            ">" => Some(TokenType::Op(Operator::GreaterThan)),
            ">=" => Some(TokenType::Op(Operator::GreaterThanOrEqual)),
            "==" => Some(TokenType::Op(Operator::Equal)),
            _ => None,
        }
    }

    pub fn is_literal(word: &str) -> Option<TokenType> {
        match word {
            "char" => Some(TokenType::Lit(Literal::Char)),
            "float" => Some(TokenType::Lit(Literal::Float)),
            "bool" => Some(TokenType::Lit(Literal::Boolean)),
            "int" => Some(TokenType::Lit(Literal::Integer)),
            "char[]" => Some(TokenType::Lit(Literal::String)),
            _ => None,
        }
    }
}

#[derive(Debug, PartialEq, Clone)]
pub enum KeyWord {
    FUNC,
    IF,
    ELSE,
    EOI,
    WHILE,
    DO,
    ARROW,
    FOR,
    RETURN,
}

#[derive(Debug, PartialEq, Clone)]
pub enum Literal {
    Integer,
    Float,
    String,
    Char,
    Boolean,
}

#[derive(Debug, PartialEq, Clone)]
pub enum Operator {
    //Arithmetic
    Plus,
    Minus,
    Multiply,
    Divide,

    //Logical
    LessThan,
    LessThanOrEqual,
    GreaterThan,
    GreaterThanOrEqual,
    Equal,
}
