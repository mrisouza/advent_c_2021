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

int get_max_position(int hor_pos[], int num_entries){
    int max = -1;
    for(int i = 0; i < num_entries; i++){
        if(max < hor_pos[i]){
            max = hor_pos[i];
        }
    }
    return max;
}

int get_lower_cost(int hor_pos[], int num_entries){
    int minimal = 100000000;
    int max = get_max_position(hor_pos, num_entries);

    for(int test_hor = 0; test_hor < max; test_hor++){
        int total = 0;
        /* how much fuel does the fish in position j use to reach test_hor */
        for(int j = 0; j < num_entries; j++){
            int dist = abs(hor_pos[j] - test_hor);
            int total_fuel = (int) dist * (dist + 1) / 2;
            total += total_fuel;
        }
        if(minimal > total){
            minimal = total;
        }
    }
    return minimal;
}
