#include <stdio.h>
#include <stdlib.h>

#include "file_handler.h"

#define COULD_NOT_OPEN_FILE "coluld not open file...\n"

FILE* get_file_pointer(char* filepath){
    FILE* pfile = fopen(filepath, "r");
    if(pfile == NULL){
        perror(COULD_NOT_OPEN_FILE);
        exit(EXIT_FAILURE);
    }
    return pfile;
}

int count_entries(FILE* pfile){
    int hor;
    int counter = 0;
    while(fscanf(pfile, "%d,", &hor) != EOF){
        counter++;
    }
    return counter;
}
