#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"

int main(int argc, char* argv[]){    
    if(argc != 2){
        printf("no input given...\n");
        exit(EXIT_FAILURE);
    }
    const char* fname = argv[1];
    fcontent f;

    FILE* pfile = open_file(fname);
    init(&f, pfile);
    read_content(&f);
    get_gamma_and_epsilon(&f);
    close_file(pfile);
    return EXIT_SUCCESS;
}
