#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "interface.h"

void init(fcontent* f, FILE* pfile){
    int c;
    int stor_size = 0;
    bool first_line = false;
    int num_bits = 0;
    while((c = getc(pfile)) != EOF){
        stor_size++;
    }
    char* content = (char *) malloc((stor_size+1) * sizeof(char));
    rewind(pfile);
    while((c = getc(pfile)) != EOF && !first_line){
        num_bits++;
        if(c == '\n'){
            first_line = true;
            num_bits--;
        }
    }
    rewind(pfile);
    int i = 0;
    while((c = getc(pfile)) != EOF){
        content[i] = c;
        i++;
    }
    f->num_bits = num_bits;
    f->content = content;
}

char bit_in_position(fcontent* f, int pos, bool is_oxygen){
    if(pos >= f->num_bits){
        printf("incorrect position...\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    f->frequency_0 = 0;
    f->frequency_1 = 0;

    while(f->content[i] != '\0'){
        int rem = i % (f->num_bits + 1); // count the last char of line
        if(f->content[i] != '\n'){
            if(rem == pos){
                if(f->content[i] == '0'){
                    f->frequency_0 += 1;
                }
                if(f->content[i] == '1'){
                    f->frequency_1 += 1;
                }
            }
        }
        i++;
    }
    if(is_oxygen){
        if(f->frequency_1 >= f->frequency_0){
            return '1';
        } else {
            return '0';
        }
    } else {
        if(f->frequency_1 >= f->frequency_0){
            return '0';
        } else {
            return '1';
        }
    }
}

void remove_bit_lines(fcontent* f, int pos, char bit){
    int i = 0;
    while(f->content[i] != '\0'){
        int rem = i % (f->num_bits+1);
        if(f->content[i] != '\n'){
            if(rem == pos){
                if(f->content[i] == bit){
                    
                }
            }
        }
    }
}

/* File handling */
FILE* open_file(const char* fname){
    FILE* pfile = fopen(fname, "r");
    if(pfile == NULL){
        printf("could not open file...\n");
        exit(EXIT_FAILURE);
    }
    return pfile;
}

void close_file(FILE* pfile){
    if(pfile == NULL){
        printf("could not close file...\n");
        exit(EXIT_FAILURE);
    }
    fclose(pfile);
}
