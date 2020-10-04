#ifndef PEAR_H
#define PEAR_H

#include <stdbool.h>

void skipShiteSpace(const char** src);

bool matchChar(
    const char*  src,
    const char** end,
    char         c,
    const char*  exclude
);

bool matchChars(
    const char*  src,
    const char** end,
    const char*  str,
    const char*  exclude
);

#endif
