#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NO_INPUT "No input given...\n"
#define NO_FILE "Could not read file...\n"

int main(int argc, char** argv){
    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    char* filepath = argv[1];
    FILE* pfile = fopen(filepath, "r");
    int c;
    bool count_char = false;
    char group[10];

    while((c = fgetc(pfile)) != EOF){
        if(c == '|'){
            count_char = true;
        }
        if(c == '\n'){
            count_char = false;
        }
        if(c == ' '){
            
        }
        if(count_char){

        }
    }
    return EXIT_SUCCESS;
}
