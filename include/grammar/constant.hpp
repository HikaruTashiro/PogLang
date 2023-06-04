#include "expr.hpp"
#include <memory>

class Const : public expr
{
    public:
        Const(std::shared_ptr<token> tok, symbol s) : expr(tok, s){}
};
