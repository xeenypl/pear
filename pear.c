#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

// for debug
#include <stdio.h>

#include "pear.h"

static int line_number = 1;

static inline bool charIsExcluded(char c, const char* exclude) {
    size_t i = 0;
    while (exclude[i] != 0) {
        if (exclude[i] == c) {
            return false;
        }
        i++;
    }
    return true;
}

static inline void addptr(const char** ptr, const char* base, size_t offset) {
    if (ptr != NULL) {
        (*ptr) = base + offset;
    }
}

void skipWhiteSpace(const char** src) {
    while (isspace(**src)) {
        if ((**src) == '\n') {
            line_number++;
        }
        (*src)++;
    }
}

int getLineNumber(void) {
    return line_number;
}

void resrtLineNumber(void) {
    line_number = 1;
}

bool matchChar(
    const char*  src,
    const char** end,
    char         c,
    const char*  exclude
) {
    if (c == (*src)) {
        if (exclude == NULL) {
            addptr(end, src, 1);
            return true;
        } else if (charIsExcluded((*(src + 1)), exclude)) {
            addptr(end, src, 1);
            return true;
        }
    }
    return false;
}

bool matchChars(
    const char*  src,
    const char** end,
    const char*  str,
    const char*  exclude
) {
    size_t len = strlen(str);
    if (strncmp(src, str, len) == 0) {
        if (exclude == NULL) {
            addptr(end, src, len);
            return true;
        } else if (charIsExcluded((*(src + 1)), exclude)) {
            addptr(end, src, len);
            return true;
        }
    }
    return false;
}

bool matchQuote(
    const char*  src,
    const char** end,
    char         quote,
    char         escape
) {
    if ((*src) == '"') {
        size_t length = 1;
        if (escape != 0) {
            while (!(((src[length] == quote) && (src[length - 1] != quote))
                  || ((src[length] == quote) && (src[length - 1] == quote)
                                             && (src[length - 2] == quote)))) {
                length++;
            }
        } else {
            while (src[length] != quote) { 
                length++;
            }
        }
        length++;
        addptr(end, src, length);
        return true;
    }
    return false;
}
