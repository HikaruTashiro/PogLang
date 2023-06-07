#include <iostream>
#include <memory>
#include "expr.hpp"
#include "stmt.hpp"
#include "../utils.hpp"

class Do : public Stmt
{
    std::shared_ptr<Expr> expression;
    std::shared_ptr<Stmt> statement;
    public:
        Do();
        void initialize(std::shared_ptr<Stmt>& st,std::shared_ptr<Expr>& e);
        void gen() override;
};
