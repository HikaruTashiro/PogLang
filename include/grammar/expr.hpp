#include "node.hpp"
#include "../token.hpp"

class expr : public node
{
    public:
        token _op;
        token _type;
        expr(token& tok, token& type);
        virtual expr gen();
        virtual expr reduce();
        virtual std::string& get_string();
        void action();
};
