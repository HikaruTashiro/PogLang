#include "logical.hpp"
#include "expr.hpp"
#include <memory>

class And : public logical
{
    public:
        And(std::shared_ptr<token> tok, std::shared_ptr<expr> e1, 
                std::shared_ptr<expr> e2) : logical(tok, e1, e2){}
};
