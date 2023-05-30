#include <array>
#include <fstream>
#include <ostream>
#include <string>
#include <list>
#include <sys/types.h>
#include <unordered_map>
#include "token.hpp"

//#define IDENTIFIER_REGEX "(([a-zA-Z]|_)([a-zA-Z]|_|\\d)*)"
//#define INTEGER_REGEX "(\\d+)u?"
//#define FLOAT_REGEX "\\d+\\.\\d*(f|lf)"
//#define ARITM_REGEX "(\\+|-|\\*|/|=)"
//#define RELAT_REGEX "(<|>|<=|>=|==)"
//#define LOGIC_REGEX "(&&|\\|\\||!)"

class lexer
{
    private:
        std::ifstream stream;
        std::string content;

        std::unordered_map<std::string, token*> words; // used to diferentiate keywords from identifiers
        uint line_count = 1u;
        uint col_count = 1u;
        char peek;
        token* get_token(std::string::iterator& iter);

    public:
        lexer(std::string file_name);
        std::list<token*> tokenize();
};
