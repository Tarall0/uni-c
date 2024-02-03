#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Defining data structure {enum, struct and array constructor(s)}
typedef enum {green, white, blue, red, black} color;

typedef struct {
    float x, y;
    color c;
} point;

typedef point set[3];

// Considering the values to print in the terminal colored text
// red \033[1;31m
// green \033[1;32m
// blue \033[1;34m
// black \033[1;30m
// white \033[1;37m

// Function to print color based on the enum value
void printColor(color c) {
    switch (c) {
        case green:
            printf("\033[1;32m"); // Green color code
            break;
        case red:
            printf("\033[1;31m"); // Red color code
            break;
        case blue:
            printf("\033[1;34m"); // Blue color code
            break;
        case black:
            printf("\033[1;30m"); // Black color code
            break;
        case white:
            printf("\033[1;37m"); // White color code
            break;
        default:
            // Default color (reset)
            printf("\033[0m");
            break;
    }
}


int main() {

    int i, j;
    set s;
    float distance, distanceX, distanceY;

    // Initialize randomly
    for(i = 0; i < 3; i = i+1){
        // Casting
        s[i].x = rand()/(float)RAND_MAX;
        s[i].y = rand()/(float)RAND_MAX;
        s[i].c = rand() % 5;
    }

    for(i = 0; i < 3; i=i+1){
        // Calculate distance of each point from each other (point i -> point j)
        for(j = i + 1; j < 3; j = j+1){
            distanceX = (s[i].x - s[j].x)*(s[i].x - s[j].x);
            distanceY = (s[i].y - s[j].y)*(s[i].y - s[j].y);
            distance = sqrt(distanceX + distanceY);

            printf("\nPoint I (%.4f, %.4f - Color: ", s[i].x, s[i].y);
            // Print the colored color number for point i
            printColor(s[i].c);
            printf("%.d", s[i].c);
            // Reset color
            printf("\033[0m");
            printf(") - ");

            printf("Point J (%.4f, %.4f - Color:", s[j].x, s[j].y);
            // Print the colored color number for point j
            printColor(s[j].c);
            printf("%.d", s[j].c);
            // Reset color
            printf("\033[0m");
            printf(") - ");
            printf(" -> Distance: %.4f\n\n", distance);
        }
    }

    return 0;
}
