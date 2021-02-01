#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "../regex.c"

int main () {
    printf ("Running test End: ");
    char *testText = "Hello World42!";
    char *regex = "42$"; // Match the center of the string.
    int result = 0;

    result = match(regex, testText);
    assert(
            result == 1, 
            "failed"
    );

    printf ("passed\n");
    return 0;
}
