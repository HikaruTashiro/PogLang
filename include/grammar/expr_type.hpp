#include <sys/types.h>
#pragma once

typedef enum : uint{
    TYPE_BOOL,
    TYPE_INT,
    TYPE_UINT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_STRING,
    TYPE_UNDETERMINED
} expr_type;
