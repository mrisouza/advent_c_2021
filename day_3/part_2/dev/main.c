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
    fcontent f, f_2;

    FILE* pfile = open_file(fname);
    FILE* pfile_2 = open_file(fname);
    init(&f, pfile);
    init(&f_2, pfile_2);
    int o_2 = get_o_2(&f);
    int c_o_2 = get_c_o_2(&f_2);
    printf("%d\n", o_2 * c_o_2);
    close_file(pfile);
    close_file(pfile_2);
    return EXIT_SUCCESS;
}
