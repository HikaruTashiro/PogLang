#include "../include/parser.hpp"

parser::parser(lexer* lex)
{
    lex->tokenize();
}

parser::~parser()
{
    delete _lex;
}
