#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include <memory>
#include "include/lexer.hpp"
#include "include/parser.hpp"
#include "include/token.hpp"

int main()
{
    //lexer lex("./test/Based.pog");
    //std::list<token_ptr> result_list = lex.tokenize();
    //for(auto var : result_list)
    //    std::cout << *var << ' ';

    parser syntax(new lexer("./test/Based.pog"));
    syntax.program();


    return 0;
}
