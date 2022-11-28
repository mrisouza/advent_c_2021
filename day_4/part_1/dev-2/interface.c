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

bool check_all_rows(board boards[]){
    bool winner_row = true;
    for(int board_num = 0; board_num < NUM_BOARDS; board_num++){
        for(int row = 0; row < SIZE_BOARDS; row++){
            winner_row = true;
            for(int col = 0; col < SIZE_BOARDS; col++){
                if(boards[board_num].rows[row][col] != -1){
                    winner_row = false;
                }
            }
            if(winner_row){
                boards[board_num].winner = true;
                return winner_row;
            }
        }
    }
    return winner_row;
}

bool check_all_cols(board boards[]){
    bool winner_col = true;
    for(int board_num = 0; board_num < NUM_BOARDS; board_num++){
        for(int col = 0; col < SIZE_BOARDS; col++){
            winner_col = true;
            for(int row = 0; row < SIZE_BOARDS; row++){
                if(boards[board_num].rows[row][col] != -1){
                    winner_col = false;
                }
            }
            if(winner_col){
                boards[board_num].winner = true;
                return winner_col;
            }
        }
    }
    return winner_col;
}

void play_game(board boards[], ll_int drawn_num[]){
    bool have_winner = false;
    int i = 0;

    while(i < DRAWN_NUMBERS && !have_winner){
        ll_int num = drawn_num[i];
        for(int l = 0; l < NUM_BOARDS; l++){
            for(int j = 0; j < SIZE_BOARDS; j++){
                for(int k = 0; k < SIZE_BOARDS; k++){
                    if(boards[l].rows[j][k] == num){
                        /* replace by -1 */
                        boards[l].rows[j][k] = -1;
                    }
                }
            }
            have_winner = check_all_rows(boards) || check_all_cols(boards);
            if(have_winner){
                boards[l].winner = have_winner;
                boards[l].last_number = drawn_num[i];
                count_unmarkeds(boards[l]);
                break;
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

void count_unmarkeds(board boards){
    ll_int total = 0;
    for(int i = 0; i < SIZE_BOARDS; i++){
        for(int j = 0; j < SIZE_BOARDS; j++){
            if(boards.rows[i][j] != -1){
                total += boards.rows[i][j];
            }
        }
    }
    printf("%lld\n", total * boards.last_number);
}
