#include <memory>
#include <iostream>
#include "expr.hpp"
#include "stmt.hpp"
#include "../utils.hpp"

class Else : public Stmt
{
    std::shared_ptr<Expr> expression;
    std::shared_ptr<Stmt> statement1;
    std::shared_ptr<Stmt> statement2;

    public:
        Else(std::shared_ptr<Expr>& e, std::shared_ptr<Stmt>& s1, std::shared_ptr<Stmt>& s2);
        void gen() override;
};
