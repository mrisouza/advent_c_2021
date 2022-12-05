#include <stdio.h>
#include <stdlib.h>

#include "lanternfish.h"

int main(int argc, char** argv){
    if(argc != 3){
        printf("no input was given...\n");
        exit(1);
    }
    char* filepath = argv[1];
    int days = atoi(argv[2]);

    lanternfish* head = create_lanternfish();
    
    FILE* pfile = fopen(filepath, "r");
    int int_time;

    while(fscanf(pfile, "%d,", &int_time) != EOF){
        add_lantern_fish(head, int_time);
    }

    for(int i = 0; i < days; i++){
        create_offspring(head);
    }

    print_num_lanternfish(head);
    free(head);
    fclose(pfile);
    return EXIT_SUCCESS;
}
