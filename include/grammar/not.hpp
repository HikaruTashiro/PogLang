#include "logical.hpp"
#include <iostream>
#include <memory>

class Not : public logical
{
    public:
        Not(std::shared_ptr<token> tok, std::shared_ptr<expr> e) : logical(tok, e, e){}

        void gen() override
        {
            std::cout << _op->get_atribute() << ' ' << expr1->get_string();
        }

        std::string get_string() override
        {
            return _op->get_atribute() + ' ' + expr1->get_string();
        }
};
