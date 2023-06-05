#include "stmt.hpp"
#include "expr.hpp"
#include <iostream>
#include <memory>

class print : public stmt
{
    std::shared_ptr<expr> expression;
    public:
        explicit print(std::shared_ptr<expr> e) : expression(e){}
        void gen() override
        {
            std::cout << "print!({}, ";
            std::cout << expression->get_string() << ");\n";
        }
};
