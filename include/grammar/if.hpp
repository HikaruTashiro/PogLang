#include "expr.hpp"
#include "stmt.hpp"
#include "../utils.hpp"
#include <memory>

class If : public stmt
{
    std::shared_ptr<expr> expression;
    std::shared_ptr<stmt> statement;
    public:
        If(std::shared_ptr<expr> e, std::shared_ptr<stmt> s)
        {
            expression = e;
            statement = s;
            assert_syntax(expression->_type == TYPE_BOOL, "Expression on if is not of the type boolean",0,0);
        }

        void gen() override
        {

        }
};
