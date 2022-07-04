#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void check_inputs(int num_inputs){
    if(num_inputs != 2){
        printf("no/nor enough inputs...\n");
        exit(EXIT_FAILURE);
    }
}

FILE* read_content(const char* fname){
    FILE* pfile = fopen(fname, "r");
    if(pfile == NULL){
        printf("could not open file...\n");
        exit(EXIT_FAILURE);
    }
    return pfile;
}

int count_file_lines(FILE* pfile){
    int c;
    int num_lines = 0;
    while((c = getc(pfile)) != EOF){
        if(c == '\n'){
            num_lines++;
        }
    }
    rewind(pfile);
    if(num_lines <= 2){
        printf("File has less than 3 lines.\n");
        fclose(pfile);
        exit(EXIT_FAILURE);
    }
    return num_lines;
}

void sonar_sweep(FILE* pfile){
    int num_lines = count_file_lines(pfile);
    int* entries = (int *) malloc(num_lines * sizeof(int));
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    int pos_sweeps = 0;
    while((read = getline(&line, &len, pfile)) != EOF){
        entries[i] = atoi(line);
        i++;
    }
    for(i = 3; i <= num_lines; i++){
        int curr = entries[i] + entries[i-1] + entries[i-2];
        int prev = entries[i-1] + entries[i-2] + entries[i-3];
        if(curr - prev > 0){
            pos_sweeps++;
        }
        
    }
    printf("%d\n", pos_sweeps);
    /* free and close */
    free(line);
    free(entries);
    fclose(pfile);
}
