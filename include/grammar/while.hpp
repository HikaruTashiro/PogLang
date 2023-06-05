#include "expr_type.hpp"
#include "stmt.hpp"
#include "expr.hpp"
#include "../utils.hpp"
#include <memory>

class While : public stmt
{
    std::shared_ptr<expr> expression;
    std::shared_ptr<stmt> statement;
    public:
        While()
        {
            expression = nullptr;
            statement = nullptr;
        }

        void initialize(std::shared_ptr<expr> e,std::shared_ptr<stmt> st)
        {
            expression = e; statement = st;
            assert_syntax(expression->_type == TYPE_BOOL, "Boolean required for expression",
                            expression->_op->_line, expression->_op->_col);
        }

        void gen() override
        {

        }
};
