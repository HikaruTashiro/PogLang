#include "expr.hpp"
#include "expr_type.hpp"
#include <memory>
#include <iostream>
#include <string>

class Const : public Expr
{
    public:
        Const(std::shared_ptr<Token> tok, Expr_type s);
        void gen() override;
};
