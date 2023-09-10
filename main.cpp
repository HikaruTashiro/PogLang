#include <regex>
#include <iostream>
#include <string>


//int main()
//{
//    /*
//     * identifiers -> (\xhh | _)(\xhh | _ | \d)*
//     * digits -> \d+ \d*
//     *
//     * selection -> if else
//     * iteration -> for while 
//     * types -> int bool float double
//     * this monstrocity -> ..
//     * */
//
//    std::string identifiers = "(([a-zA-Z]|_)(|_|\\d)*)";
//    std::string number = "(\\d+\\d*)";
//    std::string operators = "(+|-|*|/)";
//    const char* stupid = "very insane digit420 69 _";
//
//    std::regex pogzinho("(([a-zA-Z]|_)(|_|\\d)*)|(\\d+\\d*)");
//    std::string sexo (stupid);
//    std::regex_search(sexo.begin(),sexo.end(),pogzinho);
//    std::regex_search(stupid, stupid + sizeof(stupid)/sizeof(char), pogzinho);
//
//    return 0;
//}


//   ([a-zA-z]|_)([a-zA-z]|_|\\d)*

int main()
{
    std::string identifiers = "(([a-zA-Z]|_)([a-zA-Z]|_|\\d)*)";
    std::string number = "(\\d+)u?";
    std::string arit_op = "(\\+|-|\\*|/|=)";
    std::string rel_op = "(<|>|<=|>=|==)";
    std::string logic_op = "(&&|\\|\\||!)";
    std::string floating = '(' + number + "\\." + "\\d*(f|lf))";

    std::string regex = identifiers + '|' + floating + '|' + number + '|' + arit_op + '|' + logic_op;
    std::cout << "Regex: " << regex << '\n';

    //std::string s = "pogzinho(3x+4y) = pepega420 + 69.0f + 420.0lf + 420 + 42069u && ||";
    std::string s = "3 + 4 * 5.0ff";
    std::regex pattern(regex.c_str());
    std::smatch m;

    std::cout << "Input: " << s << '\n';

    //if(std::regex_search(s, m, PATTERN))
    //{
    //    auto end_last = m.end().base()->first;
    //    std::cout << "SUFFIX: " << s << '\n';
    //    std::cout << "LEXEME: " << m.begin()->str() << " ";
    //    s = m.suffix().str();
    //    do
    //    {
    //        std::cout << "SUFFIX: " << s << '\n';
    //        std::cout << "LEXEME: " << m.begin()->str() << " ";
    //        s = m.suffix().str();
    //    }while (std::regex_search(s, m, PATTERN));
    //}
    //


    // type id1,id2;
    // let id=2;
    // keyword' 'something
    //
    // peek is '=' then you have a lexeme
    // peek is ',' then you have a lexeme
    // peek is ' ' then you have a lexeme

    while (std::regex_search(s, m, pattern))
    {
        auto start = m.begin().base()->first;
        auto end = m.begin().base()->second;
        std::cout << "start: " << *start << '\n';
        std::cout << "end: " << *end << '\n';
        std::cout << "LEXEME: " << m.begin()->str() << "  string_len -> " << m.begin()->str().length() << '\n';
        s = m.suffix().str();
        std::cout << "SUFFIX: " << s << std::endl;
    }

    #define BASED 0
    return BASED;
}
