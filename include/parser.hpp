#include <iostream>
#include "lexer.hpp"
#include "grammar/stmt.hpp"
#include "grammar/constant.hpp"
#include "grammar/do.hpp"
#include "grammar/while.hpp"
#include "grammar/else.hpp"
#include "grammar/if.hpp"
#include "grammar/logical.hpp"
#include "grammar/expr.hpp"
#include "token.hpp"

class parser
{
    private:
        lexer* _lex;
        token_ptr lookahead;

        void match(symbol t);
        void move();
        stmt assign();
        stmt block();
        expr bool_expr();
        void declarations();
        expr equality();
        expr expression();
        expr factor();
        expr join();
        expr relation();
        stmt statement();
        stmt statements();
        expr term();
        expr unary();

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
