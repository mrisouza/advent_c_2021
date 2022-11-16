#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main(int argc, char** argv){
    if(argc != 3){
        printf("no input...\n");
        exit(EXIT_FAILURE);
    }
    char* fnums = argv[1];
    char* fboards = argv[2];

    FILE* pfnums = fopen(fnums, "r");
    FILE* pfboards = fopen(fboards, "r");
    
    if(pfnums == NULL || pfboards == NULL){
        perror("could not open file...\n");
        exit(EXIT_FAILURE);
    }
    int drawn_num[MAX];
    int i = 0;
    while(fscanf(pfnums, "%d,", &drawn_num[i]) != EOF){
        printf("%d\n", drawn_num[i]);
        i++;
    }

    fclose(pfnums);
    fclose(pfboards);
    return EXIT_SUCCESS;
}
