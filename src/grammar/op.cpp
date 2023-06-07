#include "../../include/grammar/op.hpp"

Op::Op(std::shared_ptr<Token> tok, Expr_type type) : Expr(tok, type) {}
