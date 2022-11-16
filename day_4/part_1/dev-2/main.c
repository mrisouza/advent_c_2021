#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "interface.h"

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
    ll_int drawn_num[MAX];
    board boards[MAX];

    get_drawn_numbers(pfnums, drawn_num);
    init_boards(pfboards, boards);

    fclose(pfnums);
    fclose(pfboards);
    return EXIT_SUCCESS;
}
