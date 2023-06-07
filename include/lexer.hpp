#include <array>
#include <fstream>
#include <memory>
#include <ostream>
#include <string>
#include <list>
#include <sys/types.h>
#include <unordered_map>
#include "token.hpp"
#pragma once

//#define IDENTIFIER_REGEX "(([a-zA-Z]|_)([a-zA-Z]|_|\\d)*)"
//#define INTEGER_REGEX "(\\d+)u?"
//#define FLOAT_REGEX "\\d+\\.\\d*(f|lf)"
//#define ARITM_REGEX "(\\+|-|\\*|/|=)"
//#define RELAT_REGEX "(<|>|<=|>=|==)"
//#define LOGIC_REGEX "(&&|\\|\\||!)"

typedef std::shared_ptr<Token> token_ptr;
typedef std::list<token_ptr> token_list;

class Lexer
{
    private:
        std::ifstream stream;
        std::string content;

        std::unordered_map<std::string, token_ptr> words; // used to diferentiate keywords from identifiers
        uint line_count = 1u;
        uint col_count = 1u;
        token_ptr get_token(std::string::iterator& iter);

    public:
        Lexer() = default;
        Lexer(std::string file_name);
        ~Lexer() = default;
        std::list<token_ptr> tokenize(); // used in debugging
};
