#include "logical.hpp"
#include "expr.hpp"
#include <iostream>
#include <memory>

class And : public logical
{
    public:
        And(std::shared_ptr<token> tok, std::shared_ptr<expr> e1, 
                std::shared_ptr<expr> e2) : logical(tok, e1, e2){}
        void gen() override
        {
            std::cout << expr1->get_string() << " && " << expr2->get_string();
        }
        
        std::string get_string() override
        {
            return expr1->get_string() + " && " + expr2->get_string();
;
        }
};
