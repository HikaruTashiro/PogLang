#include "logical.hpp"
#include <iostream>
#include <memory>

class Not : public Logical
{
    public:
        Not(std::shared_ptr<Token>& tok, std::shared_ptr<Expr> e);
        void gen() override;
};
