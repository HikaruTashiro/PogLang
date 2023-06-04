#include "logical.hpp"
#include <memory>

class Not : public logical
{
    public:
        Not(std::shared_ptr<token> tok, std::shared_ptr<expr> e);
};
