#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

FILE* open_file(const char* fname){
    FILE* pfile = fopen(fname, "r");
    if(pfile == NULL){
        printf("error opening file...\n");
        exit(EXIT_FAILURE);
    }
    return pfile;
}

void close_file(FILE* pfile){
    if(pfile == NULL){
        printf("error closing file...\n");
        exit(EXIT_FAILURE);
    }
    fclose(pfile);
}