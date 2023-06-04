#include "node.hpp"
#pragma once

class stmt : public node
{
    public:
        stmt() = default;
        virtual void gen();
};
