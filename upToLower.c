#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Introduction to Null-terminated byte strings
// A null-terminated byte string is a sequence of nonzero bytes followed by a byte with value zero (the terminating null character)
// https://en.cppreference.com/w/c/string/byte

// In the example we will convert each char to upper

int main() {
    char text[128]; // The array will occupy in the memory 128bytes however the string will contain up to 127 chars
    char *s = "Insert the words to convert\n"; // Using a pointer s to point a constant string within the ""
    char *delim = " "; 	// pointer to the null-terminated byte string identifying delimiters
    char *token;
    printf(s);

    // reading data from stdin until a newline is found or end-of-file occurs
    // using gets for the sake of knowledge (unsafe usage) https://en.cppreference.com/w/c/io/gets
    // Using fgets for safer input https://learn.microsoft.com/it-it/cpp/c-runtime-library/reference/fgets-fgetws?view=msvc-170
    fgets(text, sizeof(text), stdin);
    char *saveptr;  // for strtok_r

    // Using strtok_r function https://en.cppreference.com/w/c/string/byte/strtok char	*strtok_r(char *__str, const char *__sep, char **__lasts);
    // Following the simple for structure - init | condition | statement(s) -
    for(token = strtok_r(text, delim, &saveptr); token != NULL; token = strtok_r(NULL, delim, &saveptr)){
        int len = strlen(token);
        for(int i = 0; i < len ; i++){
            // Using toupper function for all the char in the token https://en.cppreference.com/w/c/string/byte/toupper
            token[i] = toupper(token[i]);
        }
        //converting the first char to lower case
        token[0] = tolower(token[0]);
        printf("Token: %s\n", token);

        // Add a space before the next token to reconstruct the string
        if (saveptr != NULL) {
            saveptr[-1] = ' ';
        }
    }

    printf("Text: %s", text);
    return 0;
}


