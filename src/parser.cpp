#include "../include/parser.hpp"
#include "../include/utils.hpp"
#include <memory>

parser::parser(lexer* lex)
{
    tokens = lex->tokenize(); 
    current_tok = tokens.begin();
}

parser::~parser()
{
    delete _lex;
}

void parser::match(symbol s)
{
    assert_syntax(lookahead->get_symbol() == s, "Token did not match production");
    move();
}

void parser::move()
{
    lookahead = *current_tok;
    current_tok++;
}

std::shared_ptr<stmt> parser::statements()
{
    if(lookahead->get_symbol() == RIGHT_CURLY)
        return std::shared_ptr<stmt>(new stmt());
    auto statement1 = statement();
    auto statement2 = statements();
    return std::shared_ptr<seq>(new seq(statement1, statement2));
}

std::shared_ptr<stmt> parser::statement()
{
    std::shared_ptr<expr> e;
    std::shared_ptr<stmt> s, s1, s2;
    std::shared_ptr<stmt> saved_stmt;

    switch ((uint)lookahead->get_symbol()) 
    {
        case COMMA:    
            move();
            return std::shared_ptr<stmt>(nullptr);
        case KEYWORD_IF:
            match(KEYWORD_IF); e = bool_expr(); 
            s1 = statement();
            if(lookahead->get_symbol() != KEYWORD_ELSE)
                return std::shared_ptr<If>(new If(e, s1));
            match(KEYWORD_ELSE);
            s2 = statement();
            return std::shared_ptr<Else>(new Else(e, s1, s2));
        case KEYWORD_WHILE:
            std::shared_ptr<While> while_node(new While());

        case KEYWORD_DO:
            std::shared_ptr<Do> do_node(new Do());
            
    }
}

//stmt parser::assign()
//{
//    
//}
