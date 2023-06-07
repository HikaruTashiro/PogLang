#include "logical.hpp"
#include "expr.hpp"
#include <iostream>
#include <memory>

class And : public Logical
{
    public:
        And(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1, 
                std::shared_ptr<Expr> e2);

        void gen() override;
};
