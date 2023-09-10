#include "../../include/grammar/seq.hpp"


Seq::Seq(std::shared_ptr<Stmt>& s1, std::shared_ptr<Stmt>& s2)
{
    statement1 = s1; statement2 = s2;
}

void Seq::gen()
{
    statement1->gen();
    statement2->gen();
}
