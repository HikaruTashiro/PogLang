#include "stmt.hpp"
#include "expr.hpp"
#include <memory>

class While : public stmt
{
    std::shared_ptr<expr> expression;
    std::shared_ptr<stmt> statement;
    public:
        While();
        void initialize(std::shared_ptr<expr> e,std::shared_ptr<stmt> st);
};
