#ifndef PEAR_H
#define PEAR_H

#include <stdbool.h>

void skipWhiteSpace(const char** src);

int getLineNumber(void);
void resrtLineNumber(void);

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

bool matchQuote(
    const char*  src,
    const char** end,
    char         quote,
    char         escape
);

#endif
