#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("no input given...\n");
        exit(EXIT_FAILURE);
    }
    const char* fname = argv[1];
    FILE* pfile = open_file(fname);
    close_file(pfile);
    return 0;
}