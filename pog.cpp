#include <algorithm>
#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include <memory>
#include "include/lexer.hpp"
#include "include/parser.hpp"
#include "include/token.hpp"

int main(int argc, char**argv)
{
    if(argc > 1)
    {
        std::string file_name = argv[1];
        std::string file_output(argv[1]);
        std::string extension(".pog");
        auto pos1 = file_name.find_last_of(".");
        if(pos1 == std::string::npos)
        {
            std::cout << "No extension found\n";
            return 0;
        }
        std::copy(file_name.begin() + pos1, file_name.end(), extension.begin());
        auto pos2 = file_name.find_last_of("/") + 1;
        file_output.resize(pos1 - pos2);
        std::copy(file_name.begin() + pos2, file_name.begin() + pos1, file_output.begin());
        std::cout << file_output << '\n';
        
        if(extension != ".pog")
        {
            std::cout << "Not a .pog file\n";
            return 0;
        }

        lexer lex(file_name);
        parser syntax(lex);
        syntax.program();
    }
    else
        std::cout << "File not specified\n";

    return 0;
}
