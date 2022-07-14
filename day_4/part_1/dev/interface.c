#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "interface.h"

FILE* open_file(const char* fname){
    FILE* pfile = fopen(fname, "r");
    if(pfile == NULL){
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }
    return pfile;
}

int get_num_random(char* line){
    char* pch;
    int num_calls = 0;
    pch = strtok(line, ",");
    while(pch != NULL){
        num_calls++;
        pch = strtok(NULL, ",");
    }
    return num_calls;
}

void file_handling(FILE* pfile){
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    bool is_first_line = true;
    bool get_random_num = true;
    int num_calls;
    int num_of_boards = 0;
    int* random_num;

    while((read = getline(&line, &len, pfile)) != EOF){
        if(is_first_line){
            num_calls = get_num_random(line);
            is_first_line = false;
        }
        if(line[0] == '\n'){
            num_of_boards++;
        }
    }
    random_num = (int *) malloc((num_calls + 1) * sizeof(int));
    is_first_line = true;
    int i = 0;
    rewind(pfile);
    while((read = getline(&line, &len, pfile)) != EOF){
        if(is_first_line){
            char* pch;
            pch = strtok(line, ",");
            while(pch != NULL){
                random_num[i] = atoi(pch);
                printf("%d, ", random_num[i]);
                i++;
                pch = strtok(NULL, ",");
            }
            is_first_line = false;
        }
    }
    free(random_num);
    free(line);
}
