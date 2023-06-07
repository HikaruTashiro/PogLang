#include "expr.hpp"
#include "stmt.hpp"
#include "../utils.hpp"
#include <memory>

class If : public Stmt
{
    std::shared_ptr<Expr> expression;
    std::shared_ptr<Stmt> statement;
    public:
        If(std::shared_ptr<Expr>& e, std::shared_ptr<Stmt>& s);
        void gen() override;
};
