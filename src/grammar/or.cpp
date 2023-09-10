#include "../../include/grammar/or.hpp"

Or::Or(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1,
        std::shared_ptr<Expr> e2) : Logical(tok, e1, e2){}

void Or::gen() 
{
    expr1->gen();
    std::cout << " || "; 
    expr2->gen();
}
