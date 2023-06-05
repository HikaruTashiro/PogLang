#include "expr_type.hpp"
#include "op.hpp"
#include "../utils.hpp"
#include <memory>
#include <string>

class arithm : public op 
{
    std::shared_ptr<expr> e1, e2;
    public:
        arithm(std::shared_ptr<token> tok, std::shared_ptr<expr> e1, std::shared_ptr<expr> e2) : op(tok, TYPE_BOOL)
        {
            assert_syntax(e1->_type == e2->_type, "Expressions have different type", tok->_line, tok->_col);
        }

        std::shared_ptr<expr> gen() override
        {
            return std::shared_ptr<arithm>(new arithm(_op, e1->reduce(), e2->reduce()));
        }

        std::string get_string() override
        {
            return e1->get_string() + _op->get_atribute() + e2->get_string();
        }

};
