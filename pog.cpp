#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include "include/lexer.hpp"
#include "include/token.hpp"

int main()
{
    lexer lex("./test/SEXO.pog");
    std::list<token*> result_list = lex.tokenize();
    for(auto var : result_list)
        std::cout << *var << ' ';

    //std::fstream pog("./test/SEXO.pog");
    //std::string s;
    //std::getline(pog, s);
    //std::cout << s;
    return 0;
}
