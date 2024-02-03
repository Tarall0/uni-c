#include <stdio.h>
#include <stdlib.h>

// Arguments for the main function
// n: Number of elements in the set
// k: int value for the sum of k values of the set
int main(int argc, char** argv) {

    int n, k;
    int max;

    // Handling exceptions
    // Parameters were not inserted - Usage Syntax
    if(argc != 3){
        printf("Incorrect number of parameters!\n");
        printf("%s <n> <k>\n", argv[0]); // name (w/ path) of the application argv[0]
        printf("\t n: Int value which establish the number of elements in the array");
        printf("\t k: Int value, number of k values to sum (values from array n)");

        return 1;  // exit code 1
    }

    // String to long function string, endpointer and base to convert the nr
    // https://en.cppreference.com/w/cpp/string/byte/strtol

    n = strtol(argv[1], NULL, 10);
    k = strtol(argv[2], NULL, 10);

    // Error handling
    if(n <= 0 || k <= 0) {
        printf("*** ERROR OCCURRED ***");
        printf(" - > n: %.d, k: %.d", n, k);
        printf(" || Error: n and k must be > 0");
        return 2; // exit code 2 associated to the error
    }

    // Error handling
    if(n < k){
        printf("*** ERROR OCCURRED ***");
        printf("n: %.d, k: %.d", n, k);
        printf("Error: n must be > k");
        return 3; // exit code 3 associated to the error
    }

    // constructing n array and initializing randomly
    int v[n];

    printf("[");
    for( int i = 0; i < n; i = i+1){
        v[i] = rand() % 100 + 1;
        printf(" %.d ", v[i]);
    }
    printf("]");
    printf("\n");

    max = -1;
    for(int i = 0; i <= n-k; i = i+1){
        int sum = 0;
        // Sum of all the element ins range k elements from n (i to i + k-1)
        for(int j = i; j < i + k ; j = j+1){
            sum = sum + v[j];
            printf(" %.d", v[j]);
        }
        printf(" -> Sum: %.d \n", sum);

        if(sum > max){
            max = sum;
        }
    }

    printf("Valore max: %.d", max);

    return 0;
}
