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
        if(j == SIZE_BOARDS - 1 && k == SIZE_BOARDS - 1){
            i++;
            j = 0;
            k = 0;
        } else {
            if(k == SIZE_BOARDS - 1){
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
        if(j == SIZE_BOARDS - 1 && k == SIZE_BOARDS - 1){
            i++;
            j = 0;
            k = 0;
        } else {
            if(k == SIZE_BOARDS - 1){
                j++;
                k = 0;
            } else {
                k++;
            }
        }
    }
}

void init_game(board boards[]){
    for(int i = 0; i < NUM_BOARDS; i++){
        boards[i].winner = false;
    }
}

void play_game(board boards[], ll_int drawn_num[]){
    //bool have_winner = false;
    int i = 0;

    while(i < DRAWN_NUMBERS){
        ll_int num = drawn_num[i];
        for(int l = 0; l < NUM_BOARDS; l++){
            printf("Checking board number: %d\n", l);
            for(int j = 0; j < SIZE_BOARDS; j++){
                for(int k = 0; k < SIZE_BOARDS; k++){
                    if(boards[l].rows[j][k] == num){
                        /* replace by -1 */
                        boards[l].rows[j][k] = -1;
                    }
                }
            }
        }
        i++;
    }
}

void print_boards(board boards[]){
    for(int i = 0; i < NUM_BOARDS; i++){
        printf("Board %d:\n", i);
        for(int j = 0; j < SIZE_BOARDS; j++){
            for(int k = 0; k < SIZE_BOARDS; k++){
                printf("%lld ", boards[i].rows[j][k]);
            }
            printf("\n");
        }
    }
}

void print_drawn_numbers(ll_int drawn_numbers[]){
    for(ll_int i = 0; i < DRAWN_NUMBERS; i++){
        printf("%lld\n", drawn_numbers[i]);
    }
}
