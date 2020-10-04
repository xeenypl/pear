#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "pear.h"

static void test_skipWhiteSpace(void) {
    const char* test_src = " \t\nx";
    const char* test_end = test_src;
    skipWhiteSpace(&test_end);
    assert((&test_src[3]) == test_end);
    assert(getLineNumber() == 2);
    resrtLineNumber();
    assert(getLineNumber() == 1);
}

static void test_matchChar(void) {
    const char* test_src = "ab";
    const char* test_end;
    assert(matchChar(test_src, NULL, 'a', NULL) == true);
    assert(matchChar(test_src, NULL, 'b', NULL) == false);
    assert(matchChar(test_src, NULL, 'm', NULL) == false);
    assert(matchChar(test_src, NULL, 'a', "b") == false);
    assert(matchChar(test_src, NULL, 'a', "xb") == false);
    assert(matchChar(test_src, NULL, 'a', "x") == true);
    assert(matchChar(test_src, &test_end, 'a', NULL) == true);
    assert((&test_src[1]) == test_end);
}

static void test_matchStrong(void) {
    const char* test_src = "ab";
    const char* test_end;
    assert(matchStrong(test_src, NULL, "a", NULL) == true);
    assert(matchStrong(test_src, NULL, "b", NULL) == false);
    assert(matchStrong(test_src, NULL, "m", NULL) == false);
    assert(matchStrong(test_src, NULL, "a", "b") == false);
    assert(matchStrong(test_src, NULL, "a", "xb") == false);
    assert(matchStrong(test_src, NULL, "a", "x") == true);
    assert(matchStrong(test_src, &test_end, "a", NULL) == true);
    assert((&test_src[1]) == test_end);
}

static void test_matchQuote(void) {
    const char* test_src = "'ab\\''";
    const char* test1_end;
    const char* test2_end;
    assert(matchQuote(test_src, NULL, '"', '\\') == false);
    assert(matchQuote(test_src, &test1_end, '\'', 0) == true);
    assert((&test_src[5]) == test1_end);
    assert(matchQuote(test_src, &test2_end, '\'', '\\') == true);
    assert((&test_src[6]) == test2_end);
}

int main(void) {
    test_skipWhiteSpace();
    test_matchChar();
    test_matchStrong();
    test_matchQuote();
    return 0;
}
