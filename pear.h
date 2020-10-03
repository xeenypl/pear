#ifndef PEAR_H
#define PEAR_H

#include <stdbool.h>

bool matchChar(
    const char* src,
    const char** end,
    char c,
    const char* exclude
);

#endif
