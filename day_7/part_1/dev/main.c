#include <stdio.h>
#include <stdlib.h>

#define NO_INPUT "no input was given...\n"
#define COULD_NOT_OPEN_FILE "could not open file...\n"

typedef long long unsigned int ll_int;

int main(int argc, char** argv){
    if(argc != 2){
        printf(NO_INPUT);
        exit(EXIT_FAILURE);
    }
    char* filepath = argv[1];
    FILE* pfile = fopen(filepath, "r");
    
    if(pfile == NULL){
        perror(COULD_NOT_OPEN_FILE);
        exit(EXIT_FAILURE);
    }
    
    ll_int hor;
    while(fscanf(pfile, "%lld,", &hor) != EOF){
        printf("%lld,", hor);
    }
    printf("\n");
    
    fclose(pfile);
    return EXIT_SUCCESS;
}
