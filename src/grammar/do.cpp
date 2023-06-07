#include "../../include/grammar/do.hpp"


Do::Do() : expression(nullptr), statement(nullptr) {}

void Do::initialize(std::shared_ptr<Stmt>& st,std::shared_ptr<Expr>& e)
{
    expression = e; statement = st;
    assert_syntax(expression->_type == TYPE_BOOL, "Expression is not boolean",
            expression->_op->_line, expression->_op->_col);
}

void Do::gen() 
{
    std::cout << "loop {\n";
    statement->gen();
    std::cout << "\nif !(";
    expression->gen();
    std::cout <<  ") {\nbreak;\n}\n}\n";
}
