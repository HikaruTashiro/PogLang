#include "../../include/grammar/print.hpp"

Print::Print(std::shared_ptr<Expr> e) : expression(e){}
void Print::gen()
{
    std::cout << "print!(\"{}\", ";
    expression->gen();
    std::cout << ");\n";
}
