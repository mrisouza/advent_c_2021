#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"

int main(int argc, char* argv[]){    
    if(argc != 2){
        printf("No input given...\n");
        exit(EXIT_FAILURE);
    }
    const char* fname = argv[1];
    position p;
    init_position(&p);
    FILE* pfile = open_file(fname);
    treat_file(pfile, &p);
    multiply_coordinates(&p);
    close_file(pfile);
    return EXIT_SUCCESS;
}
