/**
 * match - The Regex Match function. Call this directly.
 *
 * @param char* regexp - The regular expression pattern.
 * @param char* text - The text to search.
 */
int match(char *regexp, char *text);
/**
 * matchhere - The main algorithm for matching. All other matching functions depend on this.
 *
 * @param char* regexp - The regular expression pattern.
 * @param char* text - The text to search.
 */
int matchhere(char *regexp, char *text);
/**
 * matchstar - Matches wildcard or literal characters 0 or more times in a row.
 *
 * @param int c - The literal character c.
 * @param char* regexp - The regular expression pattern.
 * @param char* text - The text to search.
 */
int matchstar(int c, char *regexp, char *text);
/**
 * matchstar_d - Specifically for matching decimal characters 0 or more times in a row.
 *
 * @param char* regexp - The regular expression pattern.
 * @param char* text - The text to search.
 */
int matchstar_d(char *regexp, char *text);
/**
 * checkdigit - Check the current character in `text` for a digit.
 *
 * @param char* text - The text to search.
 */
int checkdigit(char* text);
/**
 * matchstar_w - Specifically for matching word characters 0 or more times in a row.
 *
 * @param char* regexp - The regular expression pattern.
 * @param char* text - The text to search.
 */
int matchstar_w(char *regexp, char *text);
/**
 * checkword - Check the current character in `text` for a word character.
 *
 * @param char* text - The text to search.
 */
int checkword(char* text);
