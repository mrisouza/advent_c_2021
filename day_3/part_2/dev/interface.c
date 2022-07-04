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
    char* content = (char *) malloc(stor_size * sizeof(char));
    rewind(pfile);
    while((c = getc(pfile)) != EOF && !first_line){
        num_bits++;
        if(c == '\n'){
            first_line = true;
            num_bits--;
        }
    }

    int* frequency_1 = (int *) malloc(num_bits * sizeof(int));
    int* frequency_0 = (int *) malloc(num_bits * sizeof(int));
    
    for(int i = 0; i<num_bits; i++){
        frequency_0[i] = 0;
        frequency_1[i] = 0;
    }
    
    rewind(pfile);
    
    int j = 0;
    int i = 0;
    while((c = getc(pfile)) != EOF){
        content[i] = c;
        int pos = j % num_bits;
        /* set frequency vector */
        if(c != '\n'){
            for(int k = 0; k<num_bits; k++){
                if(pos == k){
                    if(c == '0'){
                        frequency_0[pos] += 1;
                        j++;
                    }
                    if(c == '1'){
                        frequency_1[pos] += 1;
                        j++;
                    }
                }
            }
        }
        i++;
    }
    f->num_bits = num_bits;
    f->content = content;
    f->frequency_0 = frequency_0;
    f->frequency_1 = frequency_1;
}

void get_gamma_and_epsilon(fcontent* f){
    int gamma = 0;
    int epsilon = 0;
    for(int i = 0; i<f->num_bits; i++){
        if(f->frequency_0[i] > f->frequency_1[i]){
            gamma = 2*gamma + 0;
            epsilon = 2*epsilon + 1;
        }
        if(f->frequency_0[i] <= f->frequency_1[i]){
            gamma = 2*gamma + 1;
            epsilon = 2*epsilon + 0;
        }
    }
    printf("%d\n", gamma * epsilon);
}

void read_content(fcontent* f){
    printf("Num of bits: %d\n", f->num_bits);
    for(int i = 0; i<f->num_bits; i++){
        printf("(%d, %d)\n", f->frequency_0[i], f->frequency_1[i]);
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
