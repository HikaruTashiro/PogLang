#include <sstream>
#include <sys/types.h>
#include <utility>
#pragma once

typedef enum : uint {
    PLUS_OP,            
    MINUS_OP,           
    MUL_OP,             
    DIV_OP,             
    MODULO,             
    LOGIC_OP,           
    LESS_OR_EQUAL,
    LESS,
    GREATER_OR_EQUAL,
    GREATER,
    DIFFERENT,
    EQUAL,
    ATRIBUTION,
    IDENTIFIER,
    KEYWORD_PRINT,
    KEYWORD_IF,
    KEYWORD_ELSE,
    KEYWORD_FOR,
    KEYWORD_WHILE,
    KEYWORD_IN,
    KEYWORD_DO,
    KEYWORD_DOTDOT,
    KEYWORD_ARROW,
    KEYWORD_LET,
    CHAR_LITERAL,
    INT_LITERAL,
    BOOL_LITERAL,
    FLOAT_LITERAL,
    STRING_LITERAL,
    LEFT_SQUARE,
    RIGHT_SQUARE,
    LEFT_CURLY,
    RIGHT_CURLY,
    LEFT_PAREN,
    RIGH_PAREN,
    LEFT_BRACK,
    RIGHT_BRACK,
    SEMICOLON,
    COMMA,
    END_OF_FILE
} symbol;

class token
{
    private:
        const symbol _tag;
        const std::string _lexeme;
    public:
        ~token() = default;
        explicit token(symbol tag, std::string lexeme);
        inline symbol get_symbol(){return _tag;}
        inline const std::string& get_atribute(){return _lexeme;}
        friend std::ostream& operator<<(std::ostream& stream, token& tok);
};
