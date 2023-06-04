#include "../include/parser.hpp"
#include "../include/utils.hpp"
#include <memory>
#include <sys/types.h>

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
    assert_syntax(lookahead->get_symbol() == s, "Token did not match production",lookahead->_line, lookahead->_col);
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
    //s->gen(); // generate target code
}

std::shared_ptr<stmt> parser::block()
{
    match(LEFT_CURLY);
    std::shared_ptr<symbol_table> save_scope = scope;
    scope = std::shared_ptr<symbol_table>(new symbol_table(*scope));
    declarations(); std::shared_ptr<stmt> s = statements();
    match(RIGHT_CURLY); scope = save_scope;
    return s;
}

void parser::declarations()
{
    symbol s = lookahead->get_symbol();
    while (s == BASIC_TYPE)
    {
        std::shared_ptr<token> tok_type = type();
        std::shared_ptr<token> tok = lookahead;
        match(IDENTIFIER); match(SEMICOLON);
        std::shared_ptr<id> identifier = std::shared_ptr<id>(new id(tok, s));
        scope->put(tok, identifier);
    }
}

std::shared_ptr<token> parser::type()
{
    std::shared_ptr<token> tok = lookahead;
    match(BASIC_TYPE);
    if(lookahead->get_symbol() != LEFT_SQUARE)
        return tok;
    assert_syntax(false, "Arrays not implemented", lookahead->_line, lookahead->_col);
    return nullptr;
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
    std::shared_ptr<id> identifier = scope->get(tok);
    assert_syntax(identifier != nullptr, "Variable is undeclared", tok->_line, tok->_col);
    if(lookahead->get_symbol() == EQUAL)    // stmt -> id = expr
    {
        move();
        statement = std::shared_ptr<set>(new set(identifier,bool_expr())); 
    }
    else
    {
        assert_syntax(false, "Arrays are not implemented", lookahead->_line, lookahead->_col);
        //array acess, have no ideia how to do this one     
        //dragon book has some weird type inheritance
    }

    match(SEMICOLON);
    return statement;
}

std::shared_ptr<expr> parser::bool_expr()
{
    std::shared_ptr<expr> e = join();
    while (lookahead->get_symbol() == LOGIC_OR)
    {
        std::shared_ptr<token> tok = lookahead;
        move();
        e = std::shared_ptr<Or>(new Or(tok, e, join()));
    }
    return e;
}

std::shared_ptr<expr> parser::join()
{
    std::shared_ptr<expr> e = join();
    while (lookahead->get_symbol() == LOGIC_OR)
    {
        std::shared_ptr<token> tok = lookahead;
        move(); e = std::shared_ptr<And>(new And(tok, e, equality()));
        e = std::shared_ptr<Or>(new Or(tok, e, join()));
    }
    return e;
}

std::shared_ptr<expr> parser::equality()
{
    std::shared_ptr<expr> e = relation();
    while (lookahead->get_symbol() == EQUAL || lookahead->get_symbol() == DIFFERENT)
    {
        std::shared_ptr<token> tok = lookahead; move();
        e = std::shared_ptr<rel>(new rel(tok, e, relation()));
    }
    return e;
}

std::shared_ptr<expr> parser::relation()
{
    std::shared_ptr<expr> e = expression();
    symbol s = lookahead->get_symbol();
    if(s == LESS || s == LESS_OR_EQUAL || s == GREATER || s == GREATER_OR_EQUAL)
    {
        std::shared_ptr<token> tok = lookahead; move();
        return std::shared_ptr<rel>(new rel(tok, e, expression()));
    }
    return e;
}

std::shared_ptr<expr> parser::expression()
{
    std::shared_ptr<expr> e = term();
    while (lookahead->get_symbol() == PLUS_OP || lookahead->get_symbol() == MINUS_OP)
    {
        std::shared_ptr<token> tok = lookahead; move();
        e = std::shared_ptr<arithm>(new arithm(tok, e, term()));
    }
    return e;
}

std::shared_ptr<expr> parser::term()
{
    std::shared_ptr<expr> e = unary();
    while (lookahead->get_symbol() == MUL_OP || lookahead->get_symbol() == DIV_OP
            || lookahead->get_symbol() == MODULO)
    {
        std::shared_ptr<token> tok = lookahead; move();
        e = std::shared_ptr<arithm>(new arithm(tok, e, unary()));
    }
    return e;
}

std::shared_ptr<expr> parser::unary()
{
    if (lookahead->get_symbol() == MINUS_OP)
    {
        move(); return std::shared_ptr<Unary>(new Unary(lookahead, unary()));
    }
    else if(lookahead->get_symbol() == LOGIC_NOT)
    {
        std::shared_ptr<token> tok = lookahead; move();
        return std::shared_ptr<Not>(new Not(tok, unary()));
    }
    else 
        return factor();
}

std::shared_ptr<expr> parser::factor()
{
    std::shared_ptr<expr> e = nullptr;
    switch ((uint)lookahead->get_symbol())
    {
        case LEFT_PAREN:    
            move(); e = bool_expr(); match(RIGH_PAREN);
            return e;
        case INT_LITERAL:
        case FLOAT_LITERAL:
        case TRUE_LITERAL:
        case FALSE_LITERAL:
            e = std::shared_ptr<Const> (new Const(lookahead, lookahead->get_symbol())); move();
            return e;
        case IDENTIFIER:
            {
                std::shared_ptr<id> identifier = scope->get(lookahead);
                assert_syntax(identifier != nullptr, "Variable is undeclared", lookahead->_line, lookahead->_col);
                move();
                return identifier;
            }
        default:
            assert_syntax(false, "Factor was not identified", lookahead->_line, lookahead->_col);
            return e;
    }
}
