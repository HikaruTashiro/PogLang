#include <memory>
#include "expr.hpp"
#include "stmt.hpp"
#include "../utils.hpp"

class Else : public stmt
{
    std::shared_ptr<expr> expression;
    std::shared_ptr<stmt> statement1;
    std::shared_ptr<stmt> statement2;

    public:
        Else(std::shared_ptr<expr> e, std::shared_ptr<stmt> s1, std::shared_ptr<stmt> s2)
        {
            expression = e; statement1 = s1; statement2 = s2;
            assert_syntax(expression->_type == TYPE_BOOL, "Expression on if is not of the type boolean", 0, 0);
        }

        void gen() override
        {

        }
};
