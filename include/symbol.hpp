#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>
#include "token.hpp"
#include "grammar/id.hpp"

class Symbol
{
    private:
        std::unordered_map<std::shared_ptr<Token>, std::shared_ptr<Id>> scope;
    protected:
        Symbol* prev_scope;
    public:
        explicit Symbol(Symbol* prev);
        void put(std::shared_ptr<Token>& tok, std::shared_ptr<Id>& i);
        std::shared_ptr<Id> get(std::shared_ptr<Token>& tok);
};
