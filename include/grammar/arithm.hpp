#include "op.hpp"
#include <memory>

class arithm : public op 
{
    std::shared_ptr<expr> e1, e2;
    public:
        arithm(std::shared_ptr<token> tok, std::shared_ptr<expr> e1, std::shared_ptr<expr> e2);
        std::shared_ptr<expr> gen() override;
};
