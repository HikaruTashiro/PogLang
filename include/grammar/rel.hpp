#include "expr.hpp"
#include "expr_type.hpp"
#include "logical.hpp"
#include <iostream>
#include <memory>

class Rel : public Logical
{
    public:
        /* Expands on the right side, thus no reference there */
        Rel(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1,
                std::shared_ptr<Expr> e2);

        Expr_type check(Expr_type expr1, Expr_type expr2) override;
        void gen() override;
};

