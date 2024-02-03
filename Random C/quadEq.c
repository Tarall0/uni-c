#include <stdio.h>
#include <math.h>

int main() {
    // Coefficients of the quadratic equation: ax^2 + bx + c = 0
    float a, b, c;

    // Roots of the quadratic equation
    float x1, x2;

    // Discriminant of the quadratic equation
    float delta;

    // Initialize coefficients of the quadratic equation
    a = 50;
    b = 77;
    c = -79;

    // Calculate discriminant of the quadratic equation: Δ = b^2 - 4ac
    delta = (b * b) - 4 * a * c;

    // Print the discriminant
    printf("\nDiscriminant (Δ): %.4f", delta);

    // Check for special case when 'a' is zero
    if (a == 0) {
        printf("\n\nLinear equation: bx + c = 0\n");
        printf("\nSolution:\n");

        // Calculate and print the solution for the linear equation: x = -c / b
        float x = -c / b;
        printf("x = %.4f\n", x);
        return 0;
    }

    // Check the discriminant for the nature of the roots
    if (delta < 0) {
        // No real solutions in the set of real numbers
        printf("\nNo real solutions in ℝ\n");
    } else {
        // Calculate and print the solutions for the quadratic equation
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("\n\nSolutions:\n");
        printf("x1 = %.4f\nx2 = %.4f", x1, x2);
    }

    return 0;
}
