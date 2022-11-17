#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "interface.h"

void get_drawn_numbers(FILE* pfnums, ll_int drawn_num[]){
    int i = 0;
    while(fscanf(pfnums, "%lld,", &drawn_num[i]) != EOF){
        i++;
    }
}

void init_boards(FILE* pfboards, board boards[]){
    int i = 0, j = 0, k = 0;
    while(fscanf(pfboards, "%lld ", &boards[i].rows[j][k]) != EOF){
        if(j == MAX - 1 && k == MAX - 1){
            i++;
            j = 0;
            k = 0;
        } else {
            if(k == MAX - 1){
                j++;
                k = 0;
            } else {
                k++;
            }
        }
    }
    
    rewind(pfboards);
    i = 0, j = 0, k = 0;

    while(fscanf(pfboards, "%lld ", &boards[i].rows[j][k]) != EOF){
        if(j == MAX - 1 && k == MAX - 1){
            i++;
            j = 0;
            k = 0;
        } else {
            if(k == MAX - 1){
                j++;
                k = 0;
            } else {
                k++;
            }
        }
    }
}

void init_game(board boards[]){
    for(int i = 0; i < MAX; i++){
        boards[i].winner = false;
    }
}
