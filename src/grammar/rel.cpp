#include "../../include/grammar/rel.hpp"
#include <iostream>

Rel::Rel(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1,
        std::shared_ptr<Expr> e2) : Logical(tok, e1, e2)
{
    _type = check(expr1->_type, expr2->_type);
}

Expr_type Rel::check(Expr_type expr1, Expr_type expr2)
{
    assert_syntax(expr1 == expr2, "Wrong types for relational operation", _op->_line, _op->_col);
    return TYPE_BOOL;
}

void Rel::gen()
{
    expr1->gen();
    std::cout << _op->get_atribute();
    expr2->gen();
}
