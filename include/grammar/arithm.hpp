#include "expr_type.hpp"
#include "op.hpp"
#include "../utils.hpp"
#include <iostream>
#include <memory>
#include <string>

class arithm : public op
{
    std::shared_ptr<expr> _e1, _e2;
    public:
        arithm(std::shared_ptr<token> tok, std::shared_ptr<expr> e1, std::shared_ptr<expr> e2) 
            : op(tok, e1->_type == e2->_type ? e1->_type : TYPE_UNDETERMINED)
        {
            assert_syntax(e1->_type == e2->_type, "Expressions have different type", tok->_line, tok->_col);
            _e1 = e1; _e2 = e2;
        }

        void gen() override
        {
            _e1->gen();
            std::cout << ' ' << _op->get_atribute() << ' ';
            _e2->gen();
        }
};
