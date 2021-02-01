#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "../regex.c"

int main () {
    printf ("Running test Word: ");
    char *testText = "Hello World!";
    char *regex = "\\w!$"; // Match the center of the string.
    int result = 0;

    // Test positive case
    result = match(regex, testText);
    assert(
            result == 1, 
            "failed"
    );

    // Test negative case
    testText = "Hello World6!";
    regex = "\\w!$"; // Should not match because a decimal is in the way.
    result = match(regex, testText);
    assert(
            result != 1, 
            "failed"
    );

    printf ("passed\n");
    return 0;
}
