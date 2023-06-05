#include <cassert>
#include <cctype>
#include <list>
#include <memory>
#include <string>
#include <utility>
#include <iostream>
#include "../include/lexer.hpp"
#include "../include/utils.hpp"

lexer::lexer(std::string file_name)
{
    stream.open(file_name);
    assert(stream.is_open());
    words = { {"if", token_ptr(new token(KEYWORD_IF,"if", 0, 0))},
              {"in", token_ptr(new token(KEYWORD_IN,"in", 0, 0))},
              {"for", token_ptr(new token(KEYWORD_FOR,"for", 0, 0))},
              {"let", token_ptr(new token(KEYWORD_LET,"let", 0, 0))},
              {"else", token_ptr(new token(KEYWORD_ELSE,"else", 0, 0))},
              {"->", token_ptr(new token(KEYWORD_ARROW,"->", 0, 0))},
              {"print", token_ptr(new token(KEYWORD_PRINT,"print", 0, 0))},
              {"..", token_ptr(new token(KEYWORD_DOTDOT,"..", 0, 0))},
              {"do", token_ptr(new token(KEYWORD_DO,"do", 0, 0))},
              {"while", token_ptr(new token(KEYWORD_WHILE,"while", 0, 0))},
              {"fn", token_ptr(new token(KEYWORD_FN,"fn", 0, 0))},
              {"true", token_ptr(new token(TRUE_LITERAL,"true", 0, 0))},
              {"false", token_ptr(new token(FALSE_LITERAL,"false", 0, 0))},
              {"int", token_ptr(new token(BASIC_TYPE,"int", 0, 0))},
              {"uint", token_ptr(new token(BASIC_TYPE,"uint", 0, 0))},
              {"float", token_ptr(new token(BASIC_TYPE,"float", 0, 0))},
              {"double", token_ptr(new token(BASIC_TYPE,"double", 0, 0))},
              {"bool", token_ptr(new token(BASIC_TYPE,"bool", 0, 0))},
              {"main", token_ptr(new token(KEYWORD_MAIN,"main", 0, 0))},
              {"=", token_ptr(new token(ATRIBUTION,"=", 0, 0))},
              {"*", token_ptr(new token(MUL_OP,"*", 0, 0))},
              {"/", token_ptr(new token(DIV_OP,"/", 0, 0))},
              {"%", token_ptr(new token(MODULO,"%", 0, 0))}, 
              {"+", token_ptr(new token(PLUS_OP,"+", 0, 0))},
              {"-", token_ptr(new token(MINUS_OP,"-", 0, 0))},
              {";", token_ptr(new token(SEMICOLON,";", 0, 0))},
              {"!=", token_ptr(new token(DIFFERENT,"!=", 0, 0))},
              {"==", token_ptr(new token(EQUAL,"==", 0, 0))},
              {"<=", token_ptr(new token(LESS_OR_EQUAL,"<=", 0, 0))},
              {"<", token_ptr(new token(LESS,"<", 0, 0))},
              {">=", token_ptr(new token(GREATER_OR_EQUAL,">=", 0, 0))},
              {">", token_ptr(new token(GREATER,">", 0, 0))},
              {"&&", token_ptr(new token(LOGIC_AND,"&&", 0, 0))},
              {"||", token_ptr(new token(LOGIC_OR,"||", 0, 0))},
              {"!", token_ptr(new token(LOGIC_NOT,"!", 0, 0))},
              {"(", token_ptr(new token(LEFT_PAREN,"(", 0, 0))},
              {")", token_ptr(new token(RIGHT_PAREN,")", 0, 0))},
              {"[", token_ptr(new token(LEFT_SQUARE,"[", 0, 0))},
              {"]", token_ptr(new token(RIGHT_SQUARE,"]", 0, 0))},
              {"{", token_ptr(new token(LEFT_CURLY,"{", 0, 0))},
              {"}", token_ptr(new token(RIGHT_CURLY,"}", 0, 0))}};
}

std::list<token_ptr> lexer::tokenize()
{
    std::list<token_ptr> list;
    std::string line;
    while (!stream.eof())
    {
        std::getline(stream, line); 
        if(line.find_first_not_of(" \n\t") == std::string::npos)
            continue;
        auto start_iter = line.begin();
        while (start_iter != line.end())
            list.push_back(get_token(start_iter));
        col_count = 1;
        line_count++;
    }
    list.push_back(token_ptr(new token(END_OF_FILE, "", line_count, col_count)));
    
    return list;
}

token_ptr lexer::get_token(std::string::iterator& iter)
{
    while (true)
    {
        /* MISSING ! LOGIC OPERATOR*/
        switch (*iter)
        {
            case '\n':
                col_count = 1; line_count++; iter++;
                return nullptr;
            case ' ':
                col_count++; iter++;
                continue;
            case '\t':
                col_count += 8; iter++; //don't really know how tab will be defined
                continue;
                /*
                 * Punctiation
                 * */
            case '&':
                if(*(iter + 1) == '&')
                {
                    iter += 2;
                    col_count += 2;
                    return words.find("&&")->second;
                }
                assert_lexical(*iter == '&' && *(iter + 1) == '&', "Isolated & not allowed on the language");
            case '|':
                if(*(iter + 1) == '|')
                {
                    iter += 2;
                    col_count += 2;
                    return words.find("||")->second;
                }
                assert_lexical(*iter == '|' && *(iter + 1) == '|', "Isolated | not allowed on the language");
            case '*':
                col_count++; iter++;
                return words.find("*")->second;
            case '!':
                if(*(iter + 1) == '=')
                {
                    iter += 2;
                    col_count += 2;
                    return words.find("!=")->second;
                }
                iter++;
                col_count++;
                return words.find("!")->second;
            case '=':
                if(*(iter + 1) == '=')
                {
                    col_count++; iter++;
                    return words.find("==")->second;
                }
                col_count++; iter++;
                return words.find("=")->second;
            case '(':
            	col_count++; iter++;
                return words.find("(")->second;
            case '-':
                if(*(iter + 1) == '>')
                {
                    iter += 2;
                    col_count += 2;                    
                    return words.find("->")->second;
                }
                col_count++; iter++;
                return words.find("-")->second;
            case '+':
                col_count++; iter++;
                return words.find("+")->second;
            case ')':
                col_count++; iter++;
                return words.find(")")->second;
            case ';':
                col_count++; iter++;
                return words.find(";")->second;
            case '<':
                if (*(iter + 1) == '=')
                {
                    iter += 2;
                    col_count += 2;
                    return words.find("<=")->second;
                }
                col_count++; iter++;
                return words.find("<")->second;
            case '>':
                if (*(iter + 1) == '=')
                {
                    iter += 2; 
                    col_count += 2;
                    return words.find(">=")->second;
                }
                col_count++; iter++;
                return words.find(">")->second;
            case '/':
                col_count++; iter++;
                return words.find("/")->second;
            case '%':
                col_count++; iter++;
                return words.find("%")->second;
            case '[':
                col_count++; iter++;
                return words.find("[")->second;
            case ']':
                col_count++; iter++;
                return words.find("]")->second;
            case '{':
                col_count++; iter++;
                return words.find("{")->second;
            case '}':
                col_count++; iter++;
                return words.find("}")->second;
            case '.':
                if (*(iter + 1) == '.')
                {
                    // Only if followed by a non number
                    col_count += 2; iter += 2;
                    return words.find("..")->second;
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
            auto new_token = token_ptr(new token(IDENTIFIER, lexeme, line_count, col_count));
            words.insert(std::pair<std::string, token_ptr>(lexeme, new_token));
            return token_ptr(new_token);
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

            symbol s;
            if(isreal)
            {
                if(*iter == 'f')
                {
                    length++;
                    number_literal += *iter;
                    iter++;
                    s = FLOAT_LITERAL;
                }
                else if(*iter == 'l' && *(iter + 1) == 'f')
                {
                    length += 2;
                    number_literal += *(iter++);
                    number_literal += *(iter++);
                    s = DOUBLE_LITERAL;
                }
                else
                    assert_lexical(false, "Did not found literal specifier for float or double");
            }
            else
            {
                if(*iter == 'u') 
                {
                    length++;     
                    number_literal += *iter;
                    iter++;
                    s = UINT_LITERAL;
                }
                else
                    s = INT_LITERAL;
            }
            col_count += length;

            if(isreal)
            {
                return token_ptr(new token(s, number_literal, line_count, col_count));
            }
            else
                return token_ptr(new token(s, number_literal, line_count, col_count));
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
            return token_ptr(new token(STRING_LITERAL, literal, line_count, col_count));
        }


        // assert wrong character
        std::string s("Unexpected Character: ");
        s += *iter;
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

