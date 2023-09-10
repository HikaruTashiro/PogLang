#include "stmt.hpp"
#include "expr.hpp"
#include <iostream>
#include <memory>

class Print : public Stmt
{
    std::shared_ptr<Expr> expression;
    public:
        explicit Print(std::shared_ptr<Expr> e);
        void gen() override;
};
