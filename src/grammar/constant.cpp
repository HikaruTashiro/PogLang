#include "../../include/grammar/constant.hpp"


Const::Const(std::shared_ptr<Token> tok, Expr_type s) : Expr(tok, s){}

void Const::gen()
{
    std::cout << _op->get_atribute();
}
