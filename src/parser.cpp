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
    if(_lex != nullptr)
        delete _lex;
}

void parser::match(symbol s)
{
    assert_syntax(lookahead->get_symbol() == s, "Token did not match production",lookahead->line, lookahead->col);
    move();
}

void parser::move()
{
    lookahead = *current_tok;
    current_tok++;
}

void parser::program()
{
    std::shared_ptr<stmt> s = block(); // build syntax tree
    s->gen(); // generate target code
}

std::shared_ptr<stmt> parser::block()
{
    match(LEFT_CURLY);
    declarations();
    std::shared_ptr<stmt> s = statements();
    match(RIGHT_CURLY);
    return s;
}

void parser::declarations()
{
    symbol s = lookahead->get_symbol();
    while (true) { //this will be complicated
    
    }
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

        case KEYWORD_DO:
            {
                std::shared_ptr<Do> do_node(new Do());
                match(KEYWORD_DO);
                s1 = statement();
                match(KEYWORD_WHILE); e = bool_expr();
                match(SEMICOLON);
                do_node->initialize(s1, e);
                return do_node;
            }
        case KEYWORD_WHILE:
            {
                std::shared_ptr<While> while_node(new While());
                match(KEYWORD_WHILE); e = bool_expr(); block();
                while_node->initialize(e, s1);
                return while_node;
            }

        case RIGHT_CURLY:
            return block();

        default:
            return assign();
    }
}

std::shared_ptr<stmt> parser::assign()
{
    std::shared_ptr<stmt> statement;
    std::shared_ptr<token> tok = lookahead;
    match(IDENTIFIER);
    //symbol table
 
    return statement;
}

std::shared_ptr<expr> parser::bool_expr()
{
    std::shared_ptr<expr> e = join();
    while (lookahead->get_symbol() == LOGIC_OR)
    {
        std::shared_ptr<token> tok = lookahead;
        move();
        e = or(); // implement tomorrow
    }
}

//stmt parser::assign()
//{
//    
//}
