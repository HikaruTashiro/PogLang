#include "expr.hpp"
#include "expr_type.hpp"
#include <memory>
#pragma once

class id : public expr
{
    public:
        id(std::shared_ptr<token> id, expr_type s/*type*/) : expr(id, s){}
};
