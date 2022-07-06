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

void update_content(fcontent* f, int pos, char bit){
    int total_char = 0;
    int i = 0;
    int consider_lines = 0;
    
    while(f->content[i] != '\0'){
        total_char++;
        i++;
    }

    for(i = pos; i<total_char; i += f->num_bits+1){
        if(f->content[i] != bit){
            consider_lines++;
        }
    }

    int total_updated_char = consider_lines * (f->num_bits + 1);
    char* updated_content = (char *) malloc(total_updated_char * sizeof(char));
    i = 0;
    int j = 0;

    while(f->content[i] != '\0'){
        int rem = i % (f->num_bits + 1);
        if(rem == pos){
            if(f->content[i] != bit){
                int rep = 0;
                while(rep <= f->num_bits){
                    updated_content[j] = f->content[i-pos];
                    rep++;
                    i++;
                    j++;
                }
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    free(f->content);
    f->content = updated_content;
    
    for(i = 0; i<total_updated_char; i++){
        printf("%c", f->content[i]);
    }
    printf("\n\n");
    
}

void remove_lines(fcontent* f, int pos, bool is_oxygen){
    char bit_in_pos = bit_in_position(f, pos, is_oxygen);
    printf("Most frequent bit in pos %d: %c\n", pos, bit_in_pos);
    if(bit_in_pos == '1'){
        update_content(f, pos, '0');
    }
    if(bit_in_pos == '0'){
        update_content(f, pos, '1');
    }
}

void get_o_2(fcontent* f){
    int o_2 = 0;
    for(int i = 0; i<f->num_bits; i++){
        remove_lines(f, i, true);
    }

    for(int i = 0; i<f->num_bits; i++){
        // printf("%c\n", f->content[i]);
        if(f->content[i] == '1'){
            o_2 = 2*o_2 + 1;
        } else {
            o_2 = 2*o_2 + 0;
        }
    }
    printf("The result is: %d\n", o_2);
}

void get_c_o_2(fcontent* f){
    int c_o_2 = 0;
    for(int i = 0; i<f->num_bits; i++){
        remove_lines(f, i, false);
    }

    for(int i = 0; i<f->num_bits; i++){
        // printf("%c\n", f->content[i]);
        if(f->content[i] == '1'){
            c_o_2 = 2*c_o_2 + 1;
        } else {
            c_o_2 = 2*c_o_2 + 0;
        }
    }
    printf("The result is: %d\n", c_o_2);
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
