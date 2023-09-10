#include "../../include/grammar/not.hpp"

Not::Not(std::shared_ptr<Token>& tok, std::shared_ptr<Expr> e) : Logical(tok, e, e){}

void Not::gen()
{
    std::cout << _op->get_atribute() << ' ';
    expr1->gen();
}
