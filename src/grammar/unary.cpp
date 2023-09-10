#include "../../include/grammar/unary.hpp"

Unary::Unary(std::shared_ptr<Token>& token, std::shared_ptr<Expr> e) : Op(token, TYPE_BOOL)
{
    expression = e;
    assert_syntax(e->_type == TYPE_INT || e->_type == TYPE_FLOAT ||
            e->_type == TYPE_DOUBLE,
            "Type does not have a unary op", token->_line, token->_col);
}
void Unary::gen()
{
    std::cout << _op->get_atribute() << ' ';
    expression->gen();
    std::cout <<  ' ';
}
