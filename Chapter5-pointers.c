// Address Arithmetic

/**
 * strcpy: Copy the contents of string t to string s using pointer arithmetic.
 *
 * This function copies the characters from the source string 't' to the destination
 * string 's' using pointer arithmetic. The operation continues until the null character
 * '\0' is encountered in the source string, indicating the end of the string.
 *
 * Parameters:
 * @param s: Pointer to the destination string where the contents of 't' will be copied.
 * @param t: Pointer to the source string whose contents will be copied to 's'.
 *
 * Note:
 * - This function does not perform bounds checking.
 */
void strcpy(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/**
 * strcmp: Compare two strings, 's' and 't', and return an integer value using pointer arithmetic.
 *
 * This function compares the characters of two strings, 's' and 't', character by character.
 * It returns an integer less than, equal to, or greater than zero if 's' is found to be
 * lexicographically less than, equal to, or greater than 't', respectively.
 *
 * Parameters:
 * @param s: Pointer to the first string for comparison.
 * @param t: Pointer to the second string for comparison.
 *
 * Returns:
 * @return A negative value if 's' is lexicographically less than 't'.
 * @return 0 if 's' is lexicographically equal to 't'.
 * @return A positive value if 's' is lexicographically greater than 't'.
 *
 * Note:
 * - This function assumes that both 's' and 't' are null-terminated strings.
 */
int strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}

/**
 * strcat: Concatenate the contents of string 't' to the end of string 's' using pointer arithmetic.
 *
 * This function concatenates the characters of the source string 't' to the end of
 * the destination string 's'. The destination string 's' must have enough space to
 * accommodate the combined length of 's' and 't'.
 *
 * Parameters:
 * @param s: Pointer to the destination string to which 't' will be appended.
 * @param t: Pointer to the source string whose contents will be appended to 's'.
 *
 * Note:
 * - Ensure that the destination string 's' has sufficient space to hold the concatenated
 *   contents of both 's' and 't'. This function does not perform bounds checking.
 */
void strcat(char *s, char *t) {
    // Move to the end of the destination string 's'
    while (*s != '\0') {
        s++;
    }

    // Copy the characters of 't' to the end of 's' until the null character is encountered
    while ((*s++ = *t++) != '\0') {
        // Empty loop body; the copying is done within the condition
    }
}

/**
 * strend: Check if string 't' corresponds to a final portion of string 's' using pointer arithmetic.
 *
 * This function returns 1 if string 't' appears at the end of string 's', and
 * 0 otherwise.
 *
 * Parameters:
 * @param s: Pointer to the main string for comparison.
 * @param t: Pointer to the string to check if it is at the end of 's'.
 *
 * Returns:
 * @return 1 if 't' corresponds to a final portion of 's'.
 * @return 0 otherwise.
 */
int strend(char *s, char *t){

    while(*s != '\0')
        s++;

    while(*t != '\0')
        t++;

    while(t <= s && *s == *t){
        s--;
        t--;
    }
    
    return t < s ? 1 : 0;
}
