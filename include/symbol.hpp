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
        std::shared_ptr<symbol_table> prev_scope;
    public:
        symbol_table(symbol_table* prev) : prev_scope(prev) {}
        void put(std::shared_ptr<token>& tok, std::shared_ptr<id>& i)
        {
            scope.insert(std::pair<std::shared_ptr<token>, std::shared_ptr<id>>(tok, i));
        }

        std::shared_ptr<id> get(std::shared_ptr<token>& tok)
        {
            for (auto e = std::make_shared<symbol_table>(this); e != nullptr; e = e->prev_scope) 
            {
                auto found = e->scope.find(tok);
                if(found != scope.end())
                    return found->second;
            }
            return nullptr;
        }
        
};
