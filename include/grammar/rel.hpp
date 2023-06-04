#include "expr.hpp"
#include "logical.hpp"
#include <memory>

class rel : public logical
{
    public:
        rel(std::shared_ptr<token> tok, std::shared_ptr<expr> e1,
                std::shared_ptr<expr> e2);
};

