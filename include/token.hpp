#include <sstream>
#include <sys/types.h>
#include <utility>
#pragma once

typedef enum : uint {
    PLUS_OP,            
    MINUS_OP,           
    MUL_OP,             
    DIV_OP,             
    MODULO_OP,             
    LOGIC_OR,           
    LOGIC_AND,           
    LOGIC_NOT,           
    LESS_OR_EQUAL,
    LESS,
    GREATER_OR_EQUAL,
    GREATER,
    DIFFERENT,
    EQUAL,
    ASSIGNMENT,
    IDENTIFIER,
    KEYWORD_MAIN,
    KEYWORD_FN,
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
    BASIC_TYPE,
    TRUE_LITERAL,
    FALSE_LITERAL,
    CHAR_LITERAL,
    INT_LITERAL,
    UINT_LITERAL,
    BOOL_LITERAL,
    FLOAT_LITERAL,
    DOUBLE_LITERAL,
    STRING_LITERAL,
    LEFT_SQUARE,
    RIGHT_SQUARE,
    LEFT_CURLY,
    RIGHT_CURLY,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACK,
    RIGHT_BRACK,
    SEMICOLON,
    COMMA,
    END_OF_FILE
} Tag;

class Token
{
    private:
        const Tag _tag;
        const std::string _lexeme;
    public:
        const uint _line, _col;
        ~Token() = default;
        explicit Token(Tag tag, std::string lexeme, uint line, uint col);
        inline Tag get_symbol(){return _tag;}
        inline const std::string& get_atribute(){return _lexeme;}
        friend std::ostream& operator<<(std::ostream& stream, Token& tok);
};
