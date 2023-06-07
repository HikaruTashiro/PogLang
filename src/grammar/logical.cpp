#include "../../include/grammar/logical.hpp"


Logical::Logical(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1, std::shared_ptr<Expr>& e2)
        : Expr(tok, check(e1->_type, e2->_type)), expr1(e1), expr2(e2)
{}

Expr_type Logical::check(Expr_type s1, Expr_type s2) 
{
    if(typeid(this) == typeid(Logical))
        assert_syntax(s1 == TYPE_BOOL && s2 == TYPE_BOOL, "Operand for logical is not boolean", 0, 0);
    return TYPE_BOOL;
}
