#include "op.hpp"
#include <memory>

class Unary : public op
{
    std::shared_ptr<expr> expression;
    public:
        Unary(std::shared_ptr<token> token, std::shared_ptr<expr> e);
        std::shared_ptr<expr> gen() override;
};
