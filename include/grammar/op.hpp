#include "expr.hpp"
#include "expr_type.hpp"
#include <memory>
#pragma once

class op : public expr
{
    public:
        op(std::shared_ptr<token> tok, expr_type type) : expr(tok, type) {}
};
