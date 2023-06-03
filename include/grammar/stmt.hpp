#include "node.hpp"

class stmt : public node
{
    public:
        stmt() = default;
        virtual void gen();

};
