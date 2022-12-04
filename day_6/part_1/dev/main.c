#include <stdio.h>
#include <stdlib.h>

#include "lanternfish.h"

int main(int argc, char** argv){
    if(argc != 2){
        printf("no input was given...\n");
        exit(1);
    }
    char* filepath = argv[1];
    lanternfish* l_fish = (lanternfish *) malloc(sizeof(lanternfish));

    start(l_fish);

    return EXIT_SUCCESS;
}
