#include "expr.hpp"
#include "expr_type.hpp"
#include <memory>
#include <iostream>
#include <string>

class Const : public expr
{
    public:
        Const(std::shared_ptr<token> tok, expr_type s) : expr(tok, s){}
        std::string get_string() override
        {
            return _op->get_atribute();
        }

        void gen() override
        {
            std::cout << _op->get_atribute();
        }
};
