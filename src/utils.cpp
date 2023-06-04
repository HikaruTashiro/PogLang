#include <cstdlib>
#include <cstdio>
#include "../include/utils.hpp"

void __assert_lexical_error(const char *assertion, const char *file, unsigned int line, const char *function, const char*message)
{
    std::fprintf(stderr, 
            "%s:%u: a lexical error was detected in function %s\n"
            "The following predicate was wrong: %s\n"
            "\t%s\n", 
            file, line, function, assertion, message);
    std::abort();
}

void __assert_syntax_error(const char *assertion, const char *file, unsigned int line, const char *function, const char *message)
{
    fprintf(stderr, 
            "%s:%u: a syntax error occured in function %s\n"
            "The following sex was wrong: %s\n"
            "\t%s\n",
            file, line, function, assertion, message);
    std::abort();
}

