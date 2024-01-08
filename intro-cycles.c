#include <stdio.h>

int main() {

    typedef float temperature[6];
    float t;
    int counter, i;

    // initializing data structure
    temperature r = {20.5, 22.5, 18.9, 29.7, 30.3, 14.4};
    t = 20.0;
    counter = 0;

    for(i = 0; i < 6; i = i + 1){
        if(r[i] > t){
            counter = counter + 1;
        }
    }

    printf("Counter: %d", counter);
    printf("// Intro to for loop in C!\n");

    return 0;
}
