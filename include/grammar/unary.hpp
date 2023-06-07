#include "expr_type.hpp"
#include "../utils.hpp"
#include "op.hpp"
#include <memory>
#include <iostream>
#include <string>

class Unary : public Op
{
    std::shared_ptr<Expr> expression;
    public:
        Unary(std::shared_ptr<Token>& token, std::shared_ptr<Expr> e);
        void gen() override;
};
