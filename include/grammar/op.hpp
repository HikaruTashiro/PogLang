#include "expr.hpp"
#include <memory>
#pragma once

class op : public expr
{
    public:
        op(std::shared_ptr<token> tok, std::shared_ptr<token> type);
        std::shared_ptr<expr> reduce() override;
};
