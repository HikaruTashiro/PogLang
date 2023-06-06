#include <iostream>
#include <memory>
#include "expr.hpp"
#include "stmt.hpp"
#include "../utils.hpp"

class Do : public stmt
{
    std::shared_ptr<expr> expression;
    std::shared_ptr<stmt> statement;
    public:
        Do() : expression(nullptr), statement(nullptr) {}
        void initialize(std::shared_ptr<stmt> st,std::shared_ptr<expr> e)
        {
            expression = e; statement = st;
            assert_syntax(expression->_type == TYPE_BOOL, "Expression is not boolean",
                    expression->_op->_line, expression->_op->_col);
        }

        void gen() override
        {
            std::cout << "loop {\n";
            statement->gen();
            std::cout << "\nif !(";
            expression->gen();
            std::cout <<  ") {\nbreak;\n}\n}\n";
        }
};
