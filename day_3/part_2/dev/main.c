#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "interface.h"

int main(int argc, char* argv[]){    
    if(argc != 2){
        printf("no input given...\n");
        exit(EXIT_FAILURE);
    }
    const char* fname = argv[1];
    bool is_oxygen = true;
    fcontent f;

    FILE* pfile = open_file(fname);
    init(&f, pfile);
    char b = bit_in_position(&f, 1, is_oxygen);
    close_file(pfile);
    return EXIT_SUCCESS;
}
