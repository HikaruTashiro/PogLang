#include <cstdlib>
#include <cstdio>
#include "../include/utils.hpp"

void __assert_lexical_error(const char *__assertion, const char *__file, unsigned int __line, const char *__function, const char*message)
{
    std::fprintf(stderr, 
            "%s:%u: a lexical error was detected in function %s\n"
            "The following predicate was wrong: %s\n"
            "\t%s\n", 
            __file, __line, __function, __assertion, message);
    std::abort();
}

void __assert_syntax_error(const char *__assertion, const char *__file, unsigned int __line, const char *__function, const char *__message, uint line, uint column)
{
    fprintf(stderr, 
            "%s:%u: a syntax error occured in function %s\n"
            "The following predicate was wrong: %s\n"
            "\t%s at line:%u column:%u\n",
            __file, __line, __function, __assertion, __message, line, column);
    std::abort();
}

