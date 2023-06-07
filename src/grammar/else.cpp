#include "../../include/grammar/else.hpp"


Else::Else(std::shared_ptr<Expr>& e, std::shared_ptr<Stmt>& s1, std::shared_ptr<Stmt>& s2)
{
    expression = e; statement1 = s1; statement2 = s2;
    assert_syntax(expression->_type == TYPE_BOOL, "Expression on if is not of the type boolean", 0, 0);
}

void Else::gen() 
{
    std::cout << "if ";
    expression->gen();        
    std::cout << "\n{";
    statement1->gen();
    std::cout << "\n}\nelse\n{\n";
    statement2->gen();
    std::cout << "\n}\n";
}
