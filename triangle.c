#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    float h;
    float b;
    float a;
    unsigned int date;

    // Initialize height and base of the triangle
    // srand() seeds the pseudo-random number generator used by rand() https://en.cppreference.com/w/c/numeric/random/rand
    // In order to obtain a different seed, I approached using the current time
    date = time(NULL);
    srand(date);
    h = rand() % 100 + 1;
    b = rand() % 100 + 1;

    // Calculate area of the triangle
    // -- The less expressive type will be converted in the most expressive type
    a = h * b / 2.0;

    // Show result
    printf("** Random Generated Triangle △ **\n");
    printf("h: %3.f\n", h);
    printf("b: %3.f\n", b);
    printf("Result: %3.f", a);

    return 0;
}
