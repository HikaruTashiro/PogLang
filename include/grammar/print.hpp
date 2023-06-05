#include "stmt.hpp"
#include "expr.hpp"
#include <memory>

class print : public stmt
{
    std::shared_ptr<expr> expression;
    public:
        explicit print(std::shared_ptr<expr> e) : expression(e){}
        void gen() override
        {

        }
};
