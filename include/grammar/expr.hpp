#include "node.hpp"
#include "../token.hpp"
#include <memory>
#include "expr_type.hpp"
#pragma once

class Expr : public Node
{
    public:
        std::shared_ptr<Token> _op;
        Expr_type _type;

        Expr(std::shared_ptr<Token>& tok, Expr_type type);
        virtual void gen() = 0;
};
