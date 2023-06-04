#include "expr.hpp"
#include "stmt.hpp"
#include <memory>

class If : public stmt
{
    public:
        If(std::shared_ptr<expr> e, std::shared_ptr<stmt> s);
};
