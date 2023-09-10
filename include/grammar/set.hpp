#include <iostream>
#include <memory>
#include "id.hpp"
#include "stmt.hpp"
#include "../utils.hpp"

class Set : public Stmt
{
    private:
        std::shared_ptr<Id> identifier;
        std::shared_ptr<Expr> expression;
    public:
        Set(std::shared_ptr<Id>& i, std::shared_ptr<Expr> e);
        void gen() override;
};
