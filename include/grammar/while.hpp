#include "expr_type.hpp"
#include "stmt.hpp"
#include "expr.hpp"
#include "../utils.hpp"
#include <iostream>
#include <memory>

class While : public Stmt
{
    std::shared_ptr<Expr> expression;
    std::shared_ptr<Stmt> statement;
    public:
        While();
        void initialize(std::shared_ptr<Expr>& e,std::shared_ptr<Stmt>& st);
        void gen() override;
};
