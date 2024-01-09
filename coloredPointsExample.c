#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Defining data structure {enum, struct and array constructor(s)}
typedef enum {green, red, blue, black, white} color;

typedef struct {
    float x, y;
    color c;
} point;

typedef point set[3];

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
            printf("\nPoint I (%.4f, %.4f - Color: %.d) - Point J (%.4f, %.4f - Color: %.d): \n", s[i].x, s[i].y, s[i].c, s[j].x, s[j].y, s[j].c);
            printf(" -> Distance: %.4f\n\n", distance);
        }
    }
    
    return 0;
}
