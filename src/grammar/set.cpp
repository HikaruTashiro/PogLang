#include "../../include/grammar/set.hpp"

Set::Set(std::shared_ptr<Id>& i, std::shared_ptr<Expr> e) : identifier(i), expression(e){}

void Set::gen()
{
    identifier->gen();
    std::cout << " = ";
    expression->gen();
    std::cout << ";\n";
}
