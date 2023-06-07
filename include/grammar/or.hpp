#include <iostream>
#include <memory>
#include "logical.hpp"

class Or : public Logical
{
    public:
        Or(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1,
                std::shared_ptr<Expr> e2);
        void gen() override;
};
