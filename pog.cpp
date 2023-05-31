#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include <memory>
#include "include/lexer.hpp"
#include "include/token.hpp"

int main()
{
    lexer lex("./test/Based.pog");
    std::list<token_ptr> result_list = lex.tokenize();
    for(auto var : result_list)
        std::cout << *var << ' ';

    //std::list<std::unique_ptr<token>> pog;
    //pog.push_back((std::unique_ptr<token>(new token(KEYWORD_FOR, "for"))));
    //std::cout << pog.front().get()->get_atribute() << '\n';

    return 0;
}
