#include <cassert>
#include <cctype>
#include <list>
#include <memory>
#include <string>
#include <utility>
#include <iostream>
#include "../include/lexer.hpp"
#include "../include/utils.hpp"

Lexer::Lexer(std::string file_name) : stream(file_name)
{
    assert(stream.is_open()); 
    words = { {"if", token_ptr(new Token(KEYWORD_IF,"if", 0, 0))},
              {"in", token_ptr(new Token(KEYWORD_IN,"in", 0, 0))},
              {"for", token_ptr(new Token(KEYWORD_FOR,"for", 0, 0))},
              {"let", token_ptr(new Token(KEYWORD_LET,"let", 0, 0))},
              {"else", token_ptr(new Token(KEYWORD_ELSE,"else", 0, 0))},
              {"->", token_ptr(new Token(KEYWORD_ARROW,"->", 0, 0))},
              {"print", token_ptr(new Token(KEYWORD_PRINT,"print", 0, 0))},
              {"..", token_ptr(new Token(KEYWORD_DOTDOT,"..", 0, 0))},
              {"do", token_ptr(new Token(KEYWORD_DO,"do", 0, 0))},
              {"while", token_ptr(new Token(KEYWORD_WHILE,"while", 0, 0))},
              {"fn", token_ptr(new Token(KEYWORD_FN,"fn", 0, 0))},
              {"true", token_ptr(new Token(TRUE_LITERAL,"true", 0, 0))},
              {"false", token_ptr(new Token(FALSE_LITERAL,"false", 0, 0))},
              {"int", token_ptr(new Token(BASIC_TYPE,"int", 0, 0))},
              {"uint", token_ptr(new Token(BASIC_TYPE,"uint", 0, 0))},
              {"float", token_ptr(new Token(BASIC_TYPE,"float", 0, 0))},
              {"double", token_ptr(new Token(BASIC_TYPE,"double", 0, 0))},
              {"bool", token_ptr(new Token(BASIC_TYPE,"bool", 0, 0))},
              {"main", token_ptr(new Token(KEYWORD_MAIN,"main", 0, 0))},
              {"=", token_ptr(new Token(ATRIBUTION,"=", 0, 0))},
              {"*", token_ptr(new Token(MUL_OP,"*", 0, 0))},
              {"/", token_ptr(new Token(DIV_OP,"/", 0, 0))},
              {"%", token_ptr(new Token(MODULO,"%", 0, 0))}, 
              {"+", token_ptr(new Token(PLUS_OP,"+", 0, 0))},
              {"-", token_ptr(new Token(MINUS_OP,"-", 0, 0))},
              {";", token_ptr(new Token(SEMICOLON,";", 0, 0))},
              {"!=", token_ptr(new Token(DIFFERENT,"!=", 0, 0))},
              {"==", token_ptr(new Token(EQUAL,"==", 0, 0))},
              {"<=", token_ptr(new Token(LESS_OR_EQUAL,"<=", 0, 0))},
              {"<", token_ptr(new Token(LESS,"<", 0, 0))},
              {">=", token_ptr(new Token(GREATER_OR_EQUAL,">=", 0, 0))},
              {">", token_ptr(new Token(GREATER,">", 0, 0))},
              {"&&", token_ptr(new Token(LOGIC_AND,"&&", 0, 0))},
              {"||", token_ptr(new Token(LOGIC_OR,"||", 0, 0))},
              {"!", token_ptr(new Token(LOGIC_NOT,"!", 0, 0))},
              {"(", token_ptr(new Token(LEFT_PAREN,"(", 0, 0))},
              {")", token_ptr(new Token(RIGHT_PAREN,")", 0, 0))},
              {"[", token_ptr(new Token(LEFT_SQUARE,"[", 0, 0))},
              {"]", token_ptr(new Token(RIGHT_SQUARE,"]", 0, 0))},
              {"{", token_ptr(new Token(LEFT_CURLY,"{", 0, 0))},
              {"}", token_ptr(new Token(RIGHT_CURLY,"}", 0, 0))}};
}

std::list<token_ptr> Lexer::tokenize()
{
    std::list<token_ptr> list;
    std::string line;
    token_ptr tok;
    do
    {
        tok = get_token();
        list.push_back(tok);
    }while (tok->get_symbol() != END_OF_FILE);
    stream.close();
    
    return list;
}

token_ptr Lexer::get_token()
{
    while (true)
    {
        char current = (char)stream.get();
        char peek = stream.peek();

        if (stream.eof())
            return token_ptr(new Token(END_OF_FILE, "", line_count, col_count));
        
        switch (current)
        {
            case '\n':
                col_count = 1; line_count++;
                continue;
            case ' ':
                col_count++;
                continue;
            case '\t':
                col_count += 4; //don't really know how tab will be defined
                continue;
            /*
             * Punctuation
             * */
            case '&':
                if(peek == '&')
                {
                    stream.ignore(); col_count += 2;
                    return words.find("&&")->second;
                }
                assert_lexical(current == '&' && peek == '&', "Isolated & not allowed on the language");
            case '|':
                if(peek == '|')
                {
                    stream.ignore(); col_count += 2;
                    return words.find("||")->second;
                }
                assert_lexical(current == '|' && peek == '|', "Isolated | not allowed on the language");
            case '*':
                col_count++;
                return words.find("*")->second;
            case '!':
                if(peek == '=')
                {
                    stream.ignore(); col_count += 2;
                    return words.find("!=")->second;
                }
                col_count++;
                return words.find("!")->second;
            case '=':
                if(peek == '=')
                {
                    col_count++; stream.ignore();
                    return words.find("==")->second;
                }
                col_count++;
                return words.find("=")->second;
            case '(':
            	col_count++;
                return words.find("(")->second;
            case '-':
                if(peek == '>')
                {
                    stream.ignore(); col_count += 2;                    
                    return words.find("->")->second;
                }
                col_count++;
                return words.find("-")->second;
            case '+':
                col_count++;
                return words.find("+")->second;
            case ')':
                col_count++;
                return words.find(")")->second;
            case ';':
                col_count++;
                return words.find(";")->second;
            case '<':
                if (peek == '=')
                {
                    stream.ignore(); col_count += 2;
                    return words.find("<=")->second;
                }
                col_count++;
                return words.find("<")->second;
            case '>':
                if (peek == '=')
                {
                    stream.ignore(); col_count += 2;
                    return words.find(">=")->second;
                }
                col_count++;
                return words.find(">")->second;
            case '/':
                col_count++;
                return words.find("/")->second;
            case '%':
                col_count++;
                return words.find("%")->second;
            case '[':
                col_count++;
                return words.find("[")->second;
            case ']':
                col_count++;
                return words.find("]")->second;
            case '{':
                col_count++;
                return words.find("{")->second;
            case '}':
                col_count++;
                return words.find("}")->second;
            case '.':
                if (peek == '.')
                {
                    // Only if followed by a non number
                    stream.ignore(); col_count += 2; 
                    return words.find("..")->second;
                }
                break;
        }    

        /*
         * Keywords and Identifiers
         * */
        if (isalpha(current) || current == '_')
        {
            std::string lexeme;
            lexeme.reserve(16);
            lexeme += current;
            uint lenght = 1;
            current = stream.peek();
            while (isalpha(current) || current == '_' || isdigit(current))
            {
                //   (( [a-zA-Z] | _ )( [a-zA-Z] | _ | \\d )* )
                lenght++;
                lexeme += current;
                stream.ignore();
                current = stream.peek();
            }

            col_count += lenght;
            auto keysearch = words.find(lexeme);
            if(keysearch != words.end())
                return keysearch->second;
            auto new_token = token_ptr(new Token(IDENTIFIER, lexeme, line_count, col_count));
            words.insert(std::pair<std::string, token_ptr>(lexeme, new_token));
            return token_ptr(new_token);
        }

        /*
         * Integer or Real Literals
         * */
        if(isdigit(current) || current == '.')
        {
            std::string number_literal;
            number_literal.reserve(16);
            number_literal += current;
            bool isreal = false;

            uint length = 1;
            current = peek;
            while (isdigit(current))
            {
                length++;
                number_literal += current;
                stream.ignore();
                current = stream.peek();
            }

            if(current == '.')
            {
                length++;
                number_literal += current;
                isreal = true;
                stream.ignore();
                current = stream.peek();

                while (isdigit(current))
                {
                    length++;
                    number_literal += current;
                    stream.ignore();
                    current = stream.peek();
                }
            }

            symbol s;
            if(isreal)
            {
                stream.ignore();
                peek = stream.peek();
                if(current == 'f')
                {
                    length++;
                    s = FLOAT_LITERAL;
                }
                else if(current == 'l' && peek == 'f')
                {
                    length += 2;
                    stream.ignore();
                    s = DOUBLE_LITERAL;
                }
                else
                    assert_lexical(false, "Did not found literal specifier for float or double");
            }
            else
            {
                if(current == 'u') 
                {
                    stream.ignore();
                    length++;     
                    number_literal += current;
                    s = UINT_LITERAL;
                }
                else
                    s = INT_LITERAL;
            }
            col_count += length;

            if(isreal)
            {
                return token_ptr(new Token(s, number_literal, line_count, col_count));
            }
            else
                return token_ptr(new Token(s, number_literal, line_count, col_count));
        }

        /*
         * Literal Strings
         * */

        if(current == '"')
        {
            std::string literal;
            literal.reserve(20);
            uint length = 1;
            literal += current;
            current = stream.get();
            while (current != '\n' && current != '"')
            {
                length++;
                literal += current;
                current = stream.get();
            }

            if(current != '"')
            {
                if(current == '\n')
                    assert_lexical(current == '\n', "Unindent String");   //error assert("unindented string")
                else
                    assert_lexical(false, "Unreacheble, this should not print");
            }

            col_count += length + 1;
            literal += current;
            return token_ptr(new Token(STRING_LITERAL, literal, line_count, col_count));
        }


        // assert wrong character
        std::string s("Unexpected Character: ");
        s += current;
        s += "  line: ";
        s += std::to_string(line_count);
        s += " col: ";
        s += std::to_string(col_count);
        std::cout << s << '\n';
        assert_lexical(false, s.c_str());
    }
}

//      keyword_type id;
//      keyword_type id1,id2,i3;
//      let id=expr;
//      while bool_expr
//      for identifier in expr..expr
//      if bool_expr{stmt}(optional)else{}

