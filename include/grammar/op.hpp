#include "expr.hpp"
#include "expr_type.hpp"
#include <memory>
#pragma once

class Op : public Expr
{
    public:
        Op(std::shared_ptr<Token> tok, Expr_type type);
};
