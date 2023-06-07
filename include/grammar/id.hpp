#include "expr.hpp"
#include "expr_type.hpp"
#include <iostream>
#include <memory>
#pragma once

class Id : public Expr
{
    public:
        Id(std::shared_ptr<Token>& id, Expr_type s/*type*/);
        void gen() override;
};
