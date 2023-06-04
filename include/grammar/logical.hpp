#include "expr.hpp"
#include <memory>
#pragma once

class logical : public expr
{
    std::shared_ptr<expr> expr1, expr2;

    public:
        logical(std::shared_ptr<token>& tok, std::shared_ptr<expr>& e1,
                std::shared_ptr<expr>& e2) : expr(tok, check(e1->_type, e2->_type)), expr1(e1), expr2(e2)
        {}
        symbol check(symbol s1, symbol s2)
        {

        }

        std::shared_ptr<expr> gen() override
        {

        }
};
