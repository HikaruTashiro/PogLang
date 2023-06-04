#include <cassert>
#include <cctype>
#include <list>
#include <memory>
#include <string>
#include <utility>
#include "../include/lexer.hpp"
#include "../include/utils.hpp"

lexer::lexer(std::string file_name)
{
    stream.open(file_name);
    assert(stream.is_open());
    words = { {"if", token_ptr(new token(KEYWORD_IF,"if"))},
              {"in", token_ptr(new token(KEYWORD_IN,"in"))},
              {"for", token_ptr(new token(KEYWORD_FOR,"for"))},
              {"let", token_ptr(new token(KEYWORD_LET,"let"))},
              {"else", token_ptr(new token(KEYWORD_ELSE,"else"))},
              {"->", token_ptr(new token(KEYWORD_ARROW,"->"))},
              {"print", token_ptr(new token(KEYWORD_PRINT,"print"))},
              {"..", token_ptr(new token(KEYWORD_DOTDOT,".."))},
              {"do", token_ptr(new token(KEYWORD_DO,"do"))},
              {"true", token_ptr(new token(TRUE_LITERAL,"true"))},
              {"false", token_ptr(new token(FALSE_LITERAL,"false"))},
              {"=", token_ptr(new token(ATRIBUTION,"="))},
              {"*", token_ptr(new token(MUL_OP,"*"))},
              {"/", token_ptr(new token(DIV_OP,"/"))},
              {"%", token_ptr(new token(MODULO,"%"))}, 
              {"+", token_ptr(new token(PLUS_OP,"+"))},
              {"-", token_ptr(new token(MINUS_OP,"-"))},
              {";", token_ptr(new token(SEMICOLON,";"))},
              {"!=", token_ptr(new token(DIFFERENT,"!="))},
              {"==", token_ptr(new token(EQUAL,"=="))},
              {"<=", token_ptr(new token(LESS_OR_EQUAL,"<="))},
              {"<", token_ptr(new token(LESS,"<"))},
              {">=", token_ptr(new token(GREATER_OR_EQUAL,">="))},
              {">", token_ptr(new token(GREATER,">"))},
              {"(", token_ptr(new token(LEFT_PAREN,"("))},
              {")", token_ptr(new token(RIGH_PAREN,")"))},
              {"[", token_ptr(new token(LEFT_SQUARE,"["))},
              {"]", token_ptr(new token(RIGHT_SQUARE,"]"))},
              {"{", token_ptr(new token(LEFT_CURLY,"{"))},
              {"}", token_ptr(new token(RIGHT_CURLY,"}"))}};
}

std::list<token_ptr> lexer::tokenize()
{
    std::list<token_ptr> list;
    std::string line;
    while (!stream.eof())
    {
        std::getline(stream, line); 
        auto start_iter = line.begin();
        while (start_iter != line.end())
            list.push_back(get_token(start_iter));
        col_count = 1;
        line_count++;
    }
    list.push_back(token_ptr(new token(END_OF_FILE, "")));
    
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
                return words.find("*")->second;
            case '!':
                if(*(iter + 1) == '=')
                {
                    iter += 2;
                    col_count += 2;
                    return words.find("!=")->second;
                }
                break;
            case '=':
                if(*(iter + 1) == '=')
                {
                    col_count++;
                    iter++;
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
            auto new_token = token_ptr(new token(IDENTIFIER, lexeme));
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
                return token_ptr(new token(FLOAT_LITERAL, number_literal));
            else
                return token_ptr(new token(INT_LITERAL, number_literal));
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
            return token_ptr(new token(STRING_LITERAL, literal));
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

