#include "expr.hpp"
#include "expr_type.hpp"
#include <memory>

class Const : public expr
{
    public:
        Const(std::shared_ptr<token> tok, expr_type s) : expr(tok, s){}
};
