#include <stdio.h>
#include <stdlib.h>

#include "input_handler.h"

void get_hor_position(int hor_pos[], FILE* pfile){
    rewind(pfile);
    int i = 0;
    while(fscanf(pfile, "%d,", &hor_pos[i]) != EOF){
        i++;
    }
}

int get_lower_cost(int hor_pos[], int num_entries){
    int minimal = 1000000;
    for(int i = 0; i < num_entries; i++){
        int total = 0;
        for(int j = 0; j < num_entries; j++){
            total += abs(hor_pos[j] - hor_pos[i]);
        }
        if(total < minimal){
            minimal = total;
        }
    }
    return minimal;
}
