#include <memory>
#include "expr.hpp"
#include "stmt.hpp"

class Else : public stmt
{
    std::shared_ptr<expr> expression;
    std::shared_ptr<stmt> statement1;
    std::shared_ptr<stmt> statement2;

    public:
        Else(std::shared_ptr<expr> e,
           std::shared_ptr<stmt> s1,
             std::shared_ptr<stmt> s2);
};
