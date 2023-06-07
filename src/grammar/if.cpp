#include "../../include/grammar/if.hpp"
#include <iostream>


If::If(std::shared_ptr<Expr>& e, std::shared_ptr<Stmt>& s)
{
    expression = e;
    statement = s;
    assert_syntax(expression->_type == TYPE_BOOL, "Expression on if is not of the type boolean",0,0);
}

void If::gen()
{
    std::cout << "if ";
    expression->gen();
    std::cout << '\n';
    statement->gen();
}
