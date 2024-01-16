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
    gets(text);
    int len = strlen(text);

    // Using strtok function https://en.cppreference.com/w/c/string/byte/strtok
    // Following the simple for structure - init | condition | statement(s) -
    for(token = strtok(text, delim); token != NULL; token = strtok(NULL, delim)){
        int len = strlen(token);
        for(int i = 0; i < len ; i++){
            // Using toupper function for all the char in the token https://en.cppreference.com/w/c/string/byte/toupper
            token[i] = toupper(token[i]);
        }
        //converting the first char to lower case
        token[0] = tolower(token[0]);

        printf("Token: %s\n", token);

        //Removing the delimitator char \0 and adding a space instead to reconstruct the string
        token[len] = ' ';
    }
    // Adding terminator char to the string that was previously removed in order to reconstruct the  string
    text[len] = '\0';

    printf("Text: %s", text);

    return 0;
}
