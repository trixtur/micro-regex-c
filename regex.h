/**
 *
 */
int match(char *regexp, char *text);
/**
 *
 */
int matchhere(char *regexp, char *text);
/**
 *
 */
int matchstar(int c, char *regexp, char *text);
/**
 *
 */
int matchstar_d(char *regexp, char *text);
/**
 *
 */
int checkdigit(char* text);
/**
 *
 */
int matchstar_w(char *regexp, char *text);
/**
 * checkword - check if a word exists at the current character.
 */
int checkword(char* text);
