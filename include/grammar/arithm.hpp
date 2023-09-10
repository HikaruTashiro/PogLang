#include "expr_type.hpp"
#include "op.hpp"
#include "../utils.hpp"
#include <iostream>
#include <memory>
#include <string>

class Arithm : public Op
{
    std::shared_ptr<Expr> _e1, _e2;
    public:
        /* Expands on the right side, thus no reference there */
        Arithm(std::shared_ptr<Token>& tok, std::shared_ptr<Expr>& e1, std::shared_ptr<Expr> e2);
        void gen() override;
};
