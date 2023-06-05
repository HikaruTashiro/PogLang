#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>
#include "token.hpp"
#include "grammar/id.hpp"

class symbol_table
{
    private:
        std::unordered_map<std::shared_ptr<token>, std::shared_ptr<id>> scope;
    protected:
        symbol_table* prev_scope;
    public:
        explicit symbol_table(symbol_table* prev) : prev_scope(prev), scope() {}

        void put(std::shared_ptr<token>& tok, std::shared_ptr<id>& i)
        {
            scope.insert(std::make_pair(tok, i));
        }

        std::shared_ptr<id> get(std::shared_ptr<token>& tok)
        {
            for (auto e = this; e != nullptr; e = e->prev_scope) 
            {
                auto found = e->scope.find(tok);
                std::cout << "\tSymbol Table\n";
                for (auto elem : e->scope)
                    std::cout << '\t' << elem.first->get_atribute() << '\n';
                std::cout << '\n';
                if(found != scope.end())
                    return found->second;
            }
            return std::shared_ptr<id>();
        }
        
};
