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

        expr(std::shared_ptr<token> tok, expr_type type) : _op(tok), _type(type)
        {}

        virtual void gen(){}
        virtual std::string get_string(){return _op->get_atribute();}
};
