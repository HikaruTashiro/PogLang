#include "expr.hpp"
#include "expr_type.hpp"
#include "../utils.hpp"
#include <memory>
#include <iostream>
#include <type_traits>
#pragma once

class logical : public expr
{
    protected:
        std::shared_ptr<expr> expr1, expr2;

    public:
        logical(std::shared_ptr<token>& tok, std::shared_ptr<expr>& e1,
                std::shared_ptr<expr>& e2) : expr(tok, check(e1->_type, e2->_type)), expr1(e1), expr2(e2)
        {}

        virtual expr_type check(expr_type s1, expr_type s2) 
        {
            if(typeid(this) == typeid(logical))
                assert_syntax(s1 == TYPE_BOOL && s2 == TYPE_BOOL, "Operand for logical is not boolean", 0, 0);
            return TYPE_BOOL;
        }

        std::shared_ptr<expr> gen() override
        {

            return std::shared_ptr<expr>();
        }
};
