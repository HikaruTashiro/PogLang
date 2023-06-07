#include "expr.hpp"
#include "expr_type.hpp"
#include "../utils.hpp"
#include <memory>
#include <iostream>
#include <type_traits>
#pragma once

class Logical : public Expr
{
    protected:
        std::shared_ptr<Expr> expr1, expr2;

    public:
        Logical(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1,
                std::shared_ptr<Expr>& e2);

        virtual Expr_type check(Expr_type s1, Expr_type s2);
};
