#include <iostream>
#include "../include/token.hpp"

static const char* enum_name[]  = { "PLUS_OP", 
                                    "MINUS_OP",
                                    "MUL_OP",
                                    "DIV_OP",
                                    "MODULO",
                                    "LOGIC_OP",
                                    "LESS_OR_EQUAL",
                                    "LESS",
                                    "GREATER_OR_EQUAL",
                                    "GREATER",
                                    "RELAT_OP",
                                    "ATRIBUTION",
                                    "IDENTIFIER",
                                    "KEYWORD_PRINT",
                                    "KEYWORD_IF",
                                    "KEYWORD_ELSE",
                                    "KEYWORD_FOR",
                                    "KEYWORD_WHILE",
                                    "KEYWORD_IN",
                                    "KEYWORD_DO",
                                    "KEYWORD_DOTDOT",
                                    "KEYWORD_ARROW",
                                    "KEYWORD_LET",
                                    "CHAR_LITERAL",
                                    "INT_LITERAL",
                                    "BOOL_LITERAL",
                                    "FLOAT_LITERAL",
                                    "STRING_LITERAL",
                                    "LEFT_SQUARE",
                                    "RIGHT_SQUARE",
                                    "LEFT_CURLY",
                                    "RIGHT_CURLY",
                                    "LEFT_PAREN",
                                    "RIGH_PAREN",
                                    "LEFT_BRACK",
                                    "RIGHT_BRACK",
                                    "SEMICOLON",
                                    "COMMA",
                                    "END_OF_FILE"
                                };

token::token(symbol tag, std::string lexeme) : _tag(tag), _lexeme(lexeme){}

std::ostream& operator<<(std::ostream& stream, token& tok)
{
    stream << '<' << enum_name[tok._tag] << " , " << tok._lexeme << ">  ";
    return stream;
}
