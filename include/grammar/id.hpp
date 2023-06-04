#include "expr.hpp"
#include <memory>

class id : public expr
{
    public:
        id(std::shared_ptr<token> id, std::shared_ptr<token> p/*type*/);
};
