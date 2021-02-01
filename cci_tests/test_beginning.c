#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "../regex.c"

int main () {
    printf ("Running test Beginning: ");
    char *testText = "Hello World42!";
    char *regex = "^Hello"; // Match the center of the string.
    int result = 0;

    // Test positive case
    result = match(regex, testText);
    assert(
            result == 1, 
            "failed"
    );

    // Test negative case
    regex = "^ello"; // Match the center of the string.
    result = match(regex, testText);
    assert(
            result != 1,
            "failed"
    );

    printf ("passed\n");
    return 0;
}
