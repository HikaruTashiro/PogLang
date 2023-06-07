#include "../include/symbol.hpp"


Symbol::Symbol(Symbol* prev) : prev_scope(prev), scope() {}

void Symbol::put(std::shared_ptr<Token>& tok, std::shared_ptr<Id>& i)
{
    scope.insert(std::make_pair(tok, i));
}

std::shared_ptr<Id> Symbol::get(std::shared_ptr<Token>& tok)
{
    for (auto e = this; e != nullptr; e = e->prev_scope) 
    {
        auto found = e->scope.find(tok);
        //std::cout << "\tSymbol Table\n";
        //for (auto elem : e->scope)
        //    std::cout << '\t' << elem.first->get_atribute() << '\n';
        //std::cout << '\n';
        if(found != scope.end())
            return found->second;
    }
    return std::shared_ptr<Id>();
}
