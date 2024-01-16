#include <stdio.h>

// Introduction to files
//  Count the number of string in a file (text file)

int main(int argc, char** argv) {
    FILE * fp;
    char buff[1024];
    int counta, countb = 0;

    // Error handling if in command line was not specified the correct nr of args
    if(argc != 2){
        printf("** ERROR ** ---> Input filename must be specified");
        return 1;
    }

    // fopen function https://en.cppreference.com/w/c/io/fopen
    fp = fopen(argv[1], "r");

    if(!fp){
        printf("** ERROR ** ---> File not found: %s", argv[1]);
        return 2;
    }


    //Do while the end of the file
    while (!feof(fp)) {
        fgets(buff, 1023, fp);
        for(int i=0; i<10; i++){
            if(buff[i] == 'a'){
                counta++;
            } else if(buff[i] == 'b'){
                countb++;
            }
        }

    }

    fseek(fp, 0, SEEK_SET);

    //Do while the end of the file
    while (!feof(fp)) {
        fgets(buff, 1023, fp);
        printf("Res: %s",buff);
    }

    fclose(fp);

    printf("\n\n ----------------- \n\n");
    printf("Nr of 'a' in the file: %d\n", counta);
    printf("Nr of 'b' in the file: %d\n", countb);
    return 0;
}
