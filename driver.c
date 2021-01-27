#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "regex.c"

int main() {
    int has_match;
    char* test = "/players/trixtur/island/beach/beach42";

    // tests
    //char* regexp = "h\\d\\d$";
    //char* regexp = "h\\d*$";
    //char* regexp = "h.*$";
    char* regexp = "\\w*\\d*$";

    char *room = malloc(64);
    char *token; 
    int in_room = -1, at = 0;

    has_match = match(regexp, test);

    printf("\n");
    printf("HasMatch: %d\nRegex: %s\nTest: %s\n",
            has_match, regexp, test);

    if (has_match) {
        token = strrchr(test, '/');
        strcpy(room, token + 1);
        at = sizeof(room)-sizeof("00");
        in_room = atoi(room+at);
        room[at] = '\0';
        printf("Room: %s\nNumber: %d\n", room, in_room);
    }

    free(room);
}
