#include <iostream>
#include <list>
#include <queue>
#include <memory>
#include <utility>
#include "grammar/expr_type.hpp"
#include "lexer.hpp"
#include "grammar/stmt.hpp"
#include "grammar/constant.hpp"
#include "grammar/do.hpp"
#include "grammar/print.hpp"
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

class Parser
{
    private:
        Lexer& _lex;
        token_ptr lookahead;
        token_list tokens;
        token_list::iterator current_tok;
        Symbol* scope = nullptr;
        std::queue<std::pair<token_ptr, Expr_type>> vars;

        /* Generation */
        void gen_vars();

        /* Productions */
        void match(Tag s);
        void move();
        std::shared_ptr<Stmt> assign();
        std::shared_ptr<Stmt> block();
        std::shared_ptr<Expr> bool_expr();
        Expr_type type();
        void declarations();
        std::shared_ptr<Expr> equality();
        std::shared_ptr<Expr> expression();
        std::shared_ptr<Expr> factor();
        std::shared_ptr<Expr> join();
        std::shared_ptr<Expr> relation();
        std::shared_ptr<Stmt> statement();
        std::shared_ptr<Stmt> statements();
        std::shared_ptr<Expr> term();
        std::shared_ptr<Expr> unary();

    public:
        Parser(Lexer& lex);
        ~Parser();
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
         * factor -> ( bool ) | loc | num | real | true | false | string
         *
         * */
};
