#include "../../include/grammar/arithm.hpp"

Arithm::Arithm(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1, std::shared_ptr<Expr> e2) 
    : Op(tok, e1->_type == e2->_type ? e1->_type : TYPE_UNDETERMINED)
{
    assert_syntax(e1->_type == e2->_type, "Expressions have different type", tok->_line, tok->_col);
    _e1 = e1; _e2 = e2;
}

void Arithm::gen()
{
    _e1->gen();
    std::cout << ' ' << _op->get_atribute() << ' ';
    _e2->gen();
}

