#include <cstdlib>
#include <cstdio>
#include "../include/utils.hpp"

void __assert_lexical_fail(const char *assertion, const char *file, unsigned int line, const char *function, const char*message)
{
    std::fprintf(stderr, 
            "%s:%u: a lexical error was detected in function %s\n"
            "%s\n"
            "\t\t%s\n", 
            file, line, function, assertion, message);
    std::abort();
}
