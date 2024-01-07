#include <stdio.h>
#include <math.h>

int main() {
    // data structure
    float a, b, c;
    float x1, x2;
    float delta;

    // initialize coefficients of the equation
    a = 1;
    b = 0;
    c = -16;

    // Calculate delta of the equation
    delta = (b*b)-4*a*c;

    printf("\n△ : %4.f", delta);
    printf("\n\nSolutions:\n");

    if(a == 0) {
        printf("To implement!!!!");
        return 0;
    }


    if(delta<0) {

        printf("No solutions in R");
        return 0;

    } else {

        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);

        printf("x1 = %4.f\nx2 = %4.f", x1, x2);

    }


    return 0;
}
