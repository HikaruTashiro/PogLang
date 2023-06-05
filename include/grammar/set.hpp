#include <memory>
#include "id.hpp"
#include "stmt.hpp"
#include "../utils.hpp"

class set : public stmt
{
    private:
        std::shared_ptr<id> identifier;
        std::shared_ptr<expr> expression;
    public:
        set(std::shared_ptr<id> i, std::shared_ptr<expr> e)
        {
            identifier = i; expression = e;
        }

        void gen() override
        {

        }
};
