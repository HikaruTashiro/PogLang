#include "node.hpp"
#include "../token.hpp"
#include <memory>
#include "expr_type.hpp"
#pragma once

class expr : public node
{
    public:
        std::shared_ptr<token> _op;
        expr_type _type;
        expr(std::shared_ptr<token> tok, symbol type);
        virtual std::shared_ptr<expr> gen();
        virtual std::shared_ptr<expr> reduce();
        virtual std::string& get_string();
        void action();
};
