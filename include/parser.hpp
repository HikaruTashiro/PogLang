#include <iostream>
#include <list>
#include <memory>
#include "lexer.hpp"
#include "grammar/stmt.hpp"
#include "grammar/constant.hpp"
#include "grammar/do.hpp"
#include "grammar/while.hpp"
#include "grammar/else.hpp"
#include "grammar/if.hpp"
#include "grammar/or.hpp"
#include "grammar/and.hpp"
#include "grammar/arithm.hpp"
#include "grammar/id.hpp"
#include "grammar/logical.hpp"
#include "grammar/expr.hpp"
#include "grammar/rel.hpp"
#include "grammar/seq.hpp"
#include "grammar/set.hpp"
#include "grammar/not.hpp"
#include "grammar/unary.hpp"
#include "symbol.hpp"
#include "token.hpp"

class parser
{
    private:
        lexer* _lex;
        token_ptr lookahead;
        token_list tokens;
        token_list::iterator current_tok;
        std::shared_ptr<symbol_table> scope = nullptr;

        void match(symbol s);
        void move();
        std::shared_ptr<stmt> assign();
        std::shared_ptr<stmt> block();
        std::shared_ptr<expr> bool_expr();
        std::shared_ptr<token> type();
        void declarations();
        std::shared_ptr<expr> equality();
        std::shared_ptr<expr> expression();
        std::shared_ptr<expr> factor();
        std::shared_ptr<expr> join();
        std::shared_ptr<expr> relation();
        std::shared_ptr<stmt> statement();
        std::shared_ptr<stmt> statements();
        std::shared_ptr<expr> term();
        std::shared_ptr<expr> unary();

    public:
        parser(lexer* lex);
        ~parser();
        void program();


        /*
         * program -> fn main() block 
         * block -> { decls stmts }
         * decls -> decls decl | empty
         * decl -> type id;
         * type -> type[num] | basic //like int or float
         * stmts -> stmts stmt | empty
         * 
         * stmt -> loc = expr | bool_expr
         *      |  if bool block
         *      |  if bool block else block
         *      |  while bool block
         *      |  do block while bool_expr
         *      |  block
         *
         * bool -> bool || join | join
         * join -> join && equality | equality
         * equality -> equality == rel | equality != rel | rel
         * rel -> expr < expr | expr <= expr | expr >= expr j
         *          expr > expr | expr
         * expr -> expr + term | expr - term | term
         * term -> term * unary | term / unary | unary
         * unary -> -unary | factor
         * factor -> ( bool ) | loc | num | real | true | false
         *
         * */
};
