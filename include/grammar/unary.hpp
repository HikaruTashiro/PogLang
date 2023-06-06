#include "expr_type.hpp"
#include "../utils.hpp"
#include "op.hpp"
#include <memory>
#include <iostream>
#include <string>

class Unary : public op
{
    std::shared_ptr<expr> expression;
    public:
        Unary(std::shared_ptr<token> token, std::shared_ptr<expr> e) : op(token, TYPE_BOOL)
        {
            expression = e;
            assert_syntax(e->_type == TYPE_INT || e->_type == TYPE_FLOAT ||
                    e->_type == TYPE_DOUBLE,
                    "Type does not have a unary op", token->_line, token->_col);
        }
        void gen() override
        {
            std::cout << _op->get_atribute() << ' ' << expression->get_string() << ' ';
        }

        std::string get_string() override {return _op->get_atribute() + " " + expression->get_string();}
};
