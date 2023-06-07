#include "../../include/grammar/id.hpp"

Id::Id(std::shared_ptr<Token>& id, Expr_type s/*type*/) : Expr(id, s){}


void Id::gen() 
{
    std::cout << _op->get_atribute();
}
