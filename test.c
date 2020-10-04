#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "pear.h"

static void test_skipShiteSpace(void) {
    const char* test_src = " \t\nx";
    const char* test_end = test_src;
    skipShiteSpace(&test_end);
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

static void test_matchChars(void) {
    const char* test_src = "ab";
    const char* test_end;
    assert(matchChars(test_src, NULL, "a", NULL) == true);
    assert(matchChars(test_src, NULL, "b", NULL) == false);
    assert(matchChars(test_src, NULL, "m", NULL) == false);
    assert(matchChars(test_src, NULL, "a", "b") == false);
    assert(matchChars(test_src, NULL, "a", "xb") == false);
    assert(matchChars(test_src, NULL, "a", "x") == true);
    assert(matchChars(test_src, &test_end, "a", NULL) == true);
    assert((&test_src[1]) == test_end);
}

int main(void) {
    test_skipShiteSpace();
    test_matchChar();
    test_matchChars();
    return 0;
}
