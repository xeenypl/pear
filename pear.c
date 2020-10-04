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

void skipShiteSpace(const char** src) {
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
    const char* src,
    const char** end,
    char c,
    const char* exclude
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
}
