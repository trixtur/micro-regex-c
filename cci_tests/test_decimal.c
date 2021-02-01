#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "../regex.c"

int main () {
    printf ("Running test Decimal: ");
    char *testText = "Hello World42!";
    char *regex = "\\d\\d!$"; // Match the center of the string.
    int result = 0;

    // Test positive case
    result = match(regex, testText);
    assert(
            result == 1, 
            "failed"
    );
 
    // Test negative case
    testText = "Hello World!";
    regex = "\\d\\d!$"; // Match the center of the string.
    result = match(regex, testText);
    assert(
            result != 1, 
            "failed"
    );

    printf ("passed\n");
    return 0;
}
