#include "expr.hpp"
#include <memory>
#pragma once

class id : public expr
{
    public:
        id(std::shared_ptr<token> id, symbol s/*type*/) : expr(id, s){}
};
