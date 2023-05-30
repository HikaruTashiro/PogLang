#include <cassert>
#include <cctype>
#include <list>
#include <string>
#include <utility>
#include <iostream>
#include "../include/lexer.hpp"
#include "../include/utils.hpp"

lexer::lexer(std::string file_name)
{
    stream.open(file_name);
    assert(stream.is_open());
    words = { {"+", new token(KEYWORD_IF,"+")},
              {"-", new token(KEYWORD_IN,"+")},
              {"*", new token(KEYWORD_FOR,"+")},
              {"/", new token(KEYWORD_LET,"+")},
              {"%", new token(KEYWORD_ELSE,"+")},
              {"", new token(KEYWORD_ARROW,"+")},
              {"<=", new token(KEYWORD_PRINT,"+")},
              {"<", new token(KEYWORD_DOTDOT,"+")},
              {">=", new token(KEYWORD_DO,"+")}};
}

std::list<token*> lexer::tokenize()
{
    std::list<token*> list;
    std::string line;
    while (!stream.eof())
    {
        std::getline(stream, line); 
        std::cout << line << '\n';
        auto start_iter = line.begin();
        while (start_iter != line.end())
        {
            token* new_token = get_token(start_iter);
            list.push_back(new_token);
        }
    }
    
    return list;
}

token* lexer::get_token(std::string::iterator& iter)
{
    while (true)
    {
        std::cout << *iter << '\n';
        /* MISSING ! LOGIC OPERATOR*/
        switch (*iter)
        {
            case '\n':
                col_count = 1; line_count++; iter++;
                continue;
            case ' ':
                col_count++; iter++;
                continue;
            case '\t':
                col_count += 8; iter++; //don't really know how tab will be defined
                continue;
                /*
                 * Punctiation
                 * */
            case '*':
                col_count++; iter++;
                return new token(MUL_OP, "*");
            case '!':
                if(*(iter + 1) != '=')
                {
                    iter += 2;
                    col_count += 2;
                    return new token(RELAT_OP, "!="); //create enum for different
                }
                break;
            case '=':
                col_count++; iter++;
                return new token(ATRIBUTION, "=");
            case '(':
            	col_count++; iter++;
            	return new token(LEFT_PAREN, "(");
            case '-':
                if(*(iter + 1) == '>')
                {
                    iter += 2;
                    col_count += 2;                    
                    return new token(KEYWORD_ARROW, "->");
                }
                col_count++; iter++;
            	return new token(MINUS_OP, "-");
            case '+':
                col_count++; iter++;
                return new token(PLUS_OP, "+");
            case ')':
                col_count++; iter++;
                return new token(RIGH_PAREN, ")");
            case ';':
                col_count++; iter++;
                return new token(SEMICOLON, ";");
            case '<':
                if (*(iter + 1) == '=')
                {
                    iter += 2;
                    col_count += 2;
                    return new token(LESS_OR_EQUAL, "<=");
                }
                col_count++; iter++;
                return new token(LESS, "<");
            case '>':
                if (*(iter + 1) == '=')
                {
                    iter += 2; 
                    col_count += 2;
                  return new token(GREATER_OR_EQUAL, ">=");
                }
                col_count++; iter++;
                return new token(GREATER, ">");
            case '/':
                col_count++; iter++;
                return new token(DIV_OP, "/");
            case '%':
                col_count++; iter++;
                return new token(MODULO, "%");
            case '[':
                col_count++; iter++;
                return new token(LEFT_SQUARE, "[");
            case ']':
                col_count++; iter++;
                return new token(RIGHT_SQUARE, "]");
            case '.':
                if (*(iter + 1) == '.')
                {
                    // Only if followed by a non number
                    col_count += 2; iter += 2;
                    return new token(KEYWORD_DOTDOT, "..");
                }
                break;
        }    

        /*
         * Keywords and Identifiers
         * */
        while (isalpha(*iter) || *iter == '_')
        {
            std::string lexeme;
            lexeme.reserve(16);
            lexeme += *iter;
            uint lenght = 1;
            iter++;
            while (isalpha(*iter) || *iter == '_' || isdigit(*iter))
            {
                lenght++;
                lexeme += *iter;
                iter++;
            }

            col_count += lenght;
            auto keysearch = words.find(lexeme);
            if(keysearch != words.end())
                return keysearch->second;
            auto new_token = new token(IDENTIFIER, lexeme);
            words.insert(std::pair<std::string, token*>(lexeme, new_token));
            return new_token;
        }

        /*
         * Integer or Real Literals
         * */
        if(isdigit(*iter) || *iter == '.')
        {
            std::string number_literal;
            number_literal.reserve(16);
            number_literal += *iter;
            bool isreal = false;

            uint length = 1;
            iter++;
            while (isdigit(*iter))
            {
                length++;
                number_literal += *iter;
                iter++;
            }

            if(*iter == '.' && *(iter + 1) != '.')
            {
                isreal = true;
                while (isdigit(*iter))
                {
                    length++;
                    number_literal += *iter;
                    iter++;
                }
            }

            //while (isdigit(*iter) || (!isreal && *iter == '.'))
            //{
            //    length++; 
            //    isreal = isreal || (*iter == '.');
            //    number_literal += *iter;
            //    iter++;
            //}

            if(isreal)
            {
                if(*iter == 'f')
                {
                    length++;
                    number_literal += *iter;
                    iter++;
                }
                else if(*iter == 'l' && *(iter + 1) == 'f')
                {
                    length += 2;
                    number_literal += *(iter++);
                    number_literal += *(iter++);
                }
                else
                    assert_lexical(false, "Did not found literal specifier for float or double");
            }
            col_count += length;

            if(isreal)
                return new token(FLOAT_LITERAL, number_literal);
            else
                return new token(INT_LITERAL, number_literal);
        }

        /*
         * Literal Strings
         * */

        if(*iter == '"')
        {
            std::string literal;
            literal.reserve(20);
            uint length = 1;
            iter++;
            while (*iter != '\n' && *iter != '"')
            {
                length++;
                literal += *iter;
                iter++;
            }

            col_count += length;

            if(*iter == '\n')
              assert_lexical(*iter == '\n', "Unindent String");   //error assert("unindented string")
            else if(*iter == '"')
              iter++;
            else
              assert_lexical(false, "Unreacheble, this should not print");
            return new token(STRING_LITERAL, literal);
        }


        // assert wrong character
        std::string s("Unexpected Character: ");
        s += *iter;
        s += "  line: ";
        s += std::to_string(line_count);
        s += " col: ";
        s += std::to_string(col_count);
        assert_lexical(false, s.c_str());
    }
}

//      keyword_type id;
//      keyword_type id1,id2,i3;
//      let id=expr;
//      while bool_expr
//      for identifier in expr..expr
//      if bool_expr{stmt}(optional)else{}
