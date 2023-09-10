#include "stmt.hpp"
#include <memory>

class Seq : public Stmt
{
    std::shared_ptr<Stmt> statement1;
    std::shared_ptr<Stmt> statement2;
    public:
        Seq(std::shared_ptr<Stmt>& s1, std::shared_ptr<Stmt>& s2);
        void gen() override;
};
