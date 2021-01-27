#include "regex.h"

/*
 *  c    matches any literal character c
 *  \d   matches any decimal character
 *  \w   matches any word character
 *  .    matches any single character
 *  ^    matches the beginning of the input string
 *  $    matches the end of the input string
 *  *    matches zero or more occurrences of the previous character
 */

int match(char *regexp, char *text)
{
    if (regexp[0] == '^')
        return matchhere(regexp+1, text);
    do {    /* must look even if string is empty */
        if (matchhere(regexp, text))
            return 1;
    } while (*text++ != '\0');
    return 0;
}

/* matchhere: search for regexp at beginning of text */
int matchhere(char *regexp, char *text)
{
    if (regexp[0] == '\0')
        return 1;
    if (regexp[2] == '*' && regexp[0] == '\\')
        switch (regexp[1]) {
            case 'd': // matched \d do the test.
                return matchstar_d(regexp+3, text);
            case 'w': // matched \w do the test.
                return matchstar_w(regexp+3, text);
        }
    else if (regexp[1] == '*')
        return matchstar(regexp[0], regexp+2, text);
    if (regexp[0] == '$' && regexp[1] == '\0')
        return *text == '\0';
    if (*text!='\0') {
        switch (regexp[1]) { // Match the pattern
            case 'd': // matched \d do the test.
                if (checkdigit(text))
                    return matchhere(regexp+2, text+1);

                break;
            case 'w': // matched \w do the test.
                if (checkword(text))
                    return matchhere(regexp+2, text+1);

                break;
        }
    }  
    if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text))
        return matchhere(regexp+1, text+1);
    return 0;
}

/* matchstar: search for c*regexp at beginning of text */
int matchstar(int c, char *regexp, char *text)
{
    do {    /* a * matches zero or more instances */
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return 0;
}

/* matchstar_d: search for decimal*regex at beginning of text */
int matchstar_d(char * regexp, char* text)
{
    do { /* a * matches zero or more instances */
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && checkdigit(text++));
    return 0;
}

/* matchstar_w: search for word*regex at beginning of text */
int matchstar_w(char * regexp, char* text)
{
    do { /* a * matches zero or more instances */
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && checkword(text++));
    return 0;
}

/* checkdigit: check for a digit at the currect character. */
int checkdigit(char* text)
{
    return *text >= '0' && *text <= '9';
}

/* checkword: check for a word at the currect character. */
int checkword(char* text)
{
    return (*text >= 'a' && *text <= 'z') ||
        (*text >= 'A' && *text <= 'Z');
}
