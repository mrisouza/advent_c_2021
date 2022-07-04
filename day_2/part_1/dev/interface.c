#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "interface.h"

void init_position(position* p){
    p->hor = 0;
    p->depth = 0;
}

void move_submarine(const char* command, int value, position* p){
    if(strcmp("forward", command) == 0){
        p->hor += value;
    }
    if(strcmp(command, "up") == 0){
        p->depth += value;
    }
    if(strcmp(command, "down") == 0){
        p->depth -= value;
    }
}

void print_position(position* p){
    printf("(%d, %d)\n", p->hor, p->depth);
}

void multiply_coordinates(position* p){
    int abs_x = abs(p->hor);
    int abs_y = abs(p->depth);
    printf("%d\n", abs_x * abs_y);
}

/* file handling */
FILE* open_file(const char* fname){
    FILE* pfile = fopen(fname, "r");
    if(pfile == NULL){
        printf("could not open file.\n");
        exit(EXIT_FAILURE);
    }
    return pfile;
}

void close_file(FILE* pfile){
    if(pfile == NULL){
        printf("error closing the file...\n");
        exit(EXIT_FAILURE);
    }
    fclose(pfile);
}

void get_and_execute_command(char* line, position* p){
    int line_parity = 1;
    char* command;
    int value;

    char* pch;
    pch = strtok(line, " ");
    while(pch != NULL){
        if(line_parity == 1){
            command = pch;
            line_parity = 0;
            pch = strtok(NULL, " ");
        } else {
            value = atoi(pch);
            move_submarine(command, value, p);
            line_parity = 1;
            pch = strtok(NULL, " ");
        }
    }
}

void treat_file(FILE* pfile, position* p){
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while((read = getline(&line, &len, pfile)) != EOF){
        get_and_execute_command(line, p);
    }
    free(line);
}
