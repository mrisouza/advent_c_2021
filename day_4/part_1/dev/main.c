#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "interface.h"

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("No input file...\n");
        exit(1);
    }
    const char* fname = argv[1];
    FILE* pfile = open_file(fname);
    file_handling(pfile);
    fclose(pfile);
    return EXIT_SUCCESS;
}
