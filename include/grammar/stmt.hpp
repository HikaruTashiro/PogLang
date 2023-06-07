#include "node.hpp"
#pragma once

class Stmt : public Node
{
    public:
        Stmt() = default;
        void gen() override;
};
