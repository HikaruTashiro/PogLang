#include "expr.hpp"
#include "expr_type.hpp"
#include "../utils.hpp"
#include <memory>
#pragma once

class logical : public expr
{
    protected:
        std::shared_ptr<expr> expr1, expr2;

    public:
        logical(std::shared_ptr<token>& tok, std::shared_ptr<expr>& e1,
                std::shared_ptr<expr>& e2) : expr(tok, TYPE_UNDETERMINED), expr1(e1), expr2(e2)
        { _type = check(e1->_type, e2->_type); }
        virtual expr_type check(expr_type s1, expr_type s2) 
        {
            assert_syntax(s1 == TYPE_BOOL && s2 == TYPE_BOOL, "Operand for logical is not boolean", 0, 0);
            return TYPE_BOOL;
        }

        std::shared_ptr<expr> gen() override
        {
            return std::shared_ptr<expr>();
        }
};
