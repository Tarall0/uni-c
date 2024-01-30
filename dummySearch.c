#include <stdio.h>
#define MAXLINE 1000 // Max length of a string in input

int getLine(char s[], int lim);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // Pattern to search in the strings

// Dummy sw to find all the strings which contain the pattern
int main() {
    char line[MAXLINE];
    int  found = 0;

    while(getLine(line, MAXLINE) > 0)
        if(strindex(line, pattern) >= 0){
            printf("%s", line);
            found++;
        }

    return found;
}

/* Functions */

// getLine: Function to read a line of input into the character array 's', with a maximum limit of 'lim' characters.
// The function stops reading under the following conditions:
// 1. lim - 1 becomes zero (pre-decrement), limiting the number of characters read
// 2. The character (c = getchar()) is equal to EOF (End of File)
// 3. The character is equal to '\n' (newline character)
// Each valid character is stored in 's', and the function returns the total number of characters read.
int getLine(char s[], int lim) {
    int c, i;

    i = 0;

    // While loop to read characters until one of the stop conditions is met.
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    // If the loop stopped because of a newline character, include it in the array.
    if (c == '\n') {
        s[i++] = c;
    }

    // Null-terminate the array and return the total number of characters read.
    s[i] = '\0';
    return i;
}

// strindex: returns the index of the first occurrence of string t in string s,
// returns -1 if t is not found in s
int strindex(char s[], char t[]) {
    int i, j, k;

    // Iterate through each character in s until the end of the string
    for (i = 0; s[i] != '\0'; i++) {
        // Nested loop to compare characters of s and t starting from the current position i
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            // If a match is found and the entire t is matched, return the index i
            if (k > 0 && t[k] == '\0') {
                return i;
            }
        }
    }

    // If no match is found, return -1
    return -1;
}

