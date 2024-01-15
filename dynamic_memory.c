#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to read values from the keyboard
// Furthermore the function will also allocate the values in the memory

// The function will return the pointer of the block of the memory dynamically created
// and the number of elements that were added
int* read_values( int* n ){
    int *data = NULL;
    int len = 0; // Number of elements in the array data
    int tmp;
    char buf[8];

    // scnaf return 0 or 1, having %d we are therefore obtaing 0 (false) or 1 (true) if the conversion of the int value
    while((scanf("%d", &tmp) == 1)){
        data = realloc(data, (len)*sizeof(int));
        data[len] = tmp;
        len = len + 1;
    }
    scanf("%s", buf);
    *n = len;
    return data;
}

// Simple function to stamp the values read from the keyboard
void stamp_data(int* v, int nv){
    printf("Numero elementi: %d\n", nv);
    for(int i = 0; i < nv; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Implemented function either to shift to the right or to the left (if codes values are > or < 0
void shift(int *v, int nv, bool right){
    int tmp;
    if(right){
        // Shift to the right
        tmp = v[nv-1];

        for(int i = nv-1; i > 0; i--){
            v[i] = v[i-1];
        }

        v[0] = tmp;
    } else {
        // Shift to the left
        tmp = v[0];

        for(int i = 0; i < nv-1; i++){
            v[i] = v[i+1];
            v[nv-1] = tmp;
        }
    }
}

int main() {
    // Data structure
    int *values;
    int *codes;
    int nvalues;
    int ncodes;
    int somma = 0;

    printf("Insert the values to add in the array. To finish adding valuess add 'e'\n");
    values = read_values(&nvalues);

    printf("Insert the codes. To finish adding valuess add 'e'\n");
    codes = read_values(&ncodes);

    printf("*** Values ***\n");
    stamp_data(values, nvalues);
    printf("*** Codes ***\n");
    stamp_data(codes, ncodes);

    for(int i = 0; i < ncodes; i++){
        // Nested for in order to obtain the shift as much as the value of the code, using the absolute value of the numeber
        for(int j=0; j < abs(codes[i]); j++){
            // calling the function shift direcly using the boolean operator to verify the condition either to shift to the right or to the left
            shift(values, nvalues, codes[i]>0);
            printf("1° Element %d\n", values[0]);
            somma = somma + values[i];
        }
    }

    // free the memory
    free(values);
    free(codes);

    printf("\n*** Results  ***\n");
    printf("%d", somma);

    return 0;
}

