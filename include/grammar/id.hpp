#include "expr.hpp"
#include "expr_type.hpp"
#include <iostream>
#include <memory>
#pragma once

class id : public expr
{
    public:
        id(std::shared_ptr<token> id, expr_type s/*type*/) : expr(id, s){}

        void gen() override
        {
            std::cout << _op->get_atribute();
        }

        std::string get_string() override
        {
            return _op->get_atribute();            
        }
};
