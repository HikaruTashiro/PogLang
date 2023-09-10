#include <memory>
#include <ostream>
#include <string>
#pragma once

class Node
{
    public:
        Node() = default;
        virtual void gen() = 0;
};
