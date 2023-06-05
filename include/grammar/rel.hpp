#include "expr.hpp"
#include "expr_type.hpp"
#include "logical.hpp"
#include <memory>

class rel : public logical
{
    public:
        rel(std::shared_ptr<token> tok, std::shared_ptr<expr> e1,
                std::shared_ptr<expr> e2) : logical(tok, e1, e2){_type = check(expr1->_type, expr2->_type);}
        expr_type check(expr_type expr1, expr_type expr2) override
        {
            assert_syntax(expr1 == expr2, "Wrong types for relational operation", _op->_line, _op->_col);
            return TYPE_BOOL;
        }
};

