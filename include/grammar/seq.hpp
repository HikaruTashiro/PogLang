#include "stmt.hpp"
#include <memory>

class seq : public stmt
{
    std::shared_ptr<stmt> statement1;
    std::shared_ptr<stmt> statement2;
    public:
        seq(std::shared_ptr<stmt>& s1, std::shared_ptr<stmt>& s2)
        {
            statement1 = s1; statement2 = s2;
        }

        void gen() override
        {
            statement1->gen();
            statement2->gen();
        }
};
