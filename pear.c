#include <stdbool.h>
#include <stddef.h>

// for debug
#include <stdio.h>

#include "pear.h"

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
