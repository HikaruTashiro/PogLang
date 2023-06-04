#include "stmt.hpp"
#include "expr.hpp"
#include <memory>

/* THIS IS RETARDED */
class Do : public stmt
{
    std::shared_ptr<expr> expression;
    std::shared_ptr<stmt> statement;
    public:
        Do();
        void initialize(std::shared_ptr<expr> e,std::shared_ptr<stmt> st);
};
