#include "../../include/grammar/while.hpp"

While::While() : expression(nullptr), statement(nullptr){}

void While::initialize(std::shared_ptr<Expr>& e,std::shared_ptr<Stmt>& st)
{
    expression = e; statement = st;
    assert_syntax(expression->_type == TYPE_BOOL, "Boolean required for expression",
                    expression->_op->_line, expression->_op->_col);
}

void While::gen()
{
    std::cout << "while ";
    expression->gen();
    std::cout << "{\n";
    statement->gen();
    std::cout << "\n}\n";
}
