#include <stdio.h>
#include <stdlib.h>

/**
 * Mini program to calculate the cumulative sum of the elements of an array v.
 */

typedef int set[10];

int main() {
    int i;
    set v, r;

    // Generate and display random values for array v
    printf("\nArray S\n");
    for(i = 0; i < 10; i++){
        v[i] = rand() % 201 - 100;
        printf("%d ", v[i]);
    }

    // Calculate cumulative sum and store the result in array r
    printf("\nArray R\n");
    for(i = 0; i < 10; i++){
        int sum = 0;
        for(int j = 0; j <= i; j++){
            sum += v[j];
        }

        r[i] = sum;
        printf("%d ", r[i]);
    }

    return 0;
}
