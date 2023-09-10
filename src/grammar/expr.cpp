#include "../../include/grammar/expr.hpp"


Expr::Expr(std::shared_ptr<Token>& tok, Expr_type type) : _op(tok), _type(type){}
