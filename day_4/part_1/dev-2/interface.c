#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "interface.h"

void get_drawn_numbers(FILE* pfnums, ll_int drawn_num[]){
    int i = 0;
    while(fscanf(pfnums, "%lld,", &drawn_num[i]) != EOF){
        printf("%lld\n", drawn_num[i]);
        i++;
    }
}

void init_boards(FILE* pfboards, board boards[]){
    int i = 0;
    while (fscanf(pfboards, "%lld %lld %lld %lld %lld", boards[i].rows[0], boards[i].rows[1], boards[i].rows[2], boards[i].rows[3], boards[i].rows[4]) != EOF){
        boards[i].cols[i]

    }
}
