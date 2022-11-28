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
    int num_board = 0, r = 0, c = 0;
    while(fscanf(pfboards, "%lld ", &boards[num_board].rows[r][c]) != EOF){
        if(r == SIZE_BOARDS - 1 && c == SIZE_BOARDS - 1){
            num_board++;
            r = 0;
            c = 0;
        } else {
            if(c == SIZE_BOARDS - 1){
                r++;
                c = 0;
            } else {
                c++;
            }
        }
    }

    rewind(pfboards);
    num_board = 0, r = 0, c = 0;

    while(fscanf(pfboards, "%lld ", &boards[num_board].cols[r][c]) != EOF){
        if(r == SIZE_BOARDS - 1 && c == SIZE_BOARDS - 1){
            num_board++;
            r = 0;
            c = 0;
        } else {
            if(r == SIZE_BOARDS - 1){
                c++;
                r = 0;
            } else {
                r++;
            }
        }
    }
}

void init_game(board boards[]){
    for(int i = 0; i < NUM_BOARDS; i++){
        boards[i].winner = false;
    }
}

bool check_board(board boards[], int board_num){
    bool is_winner = boards[board_num].winner;
    bool have_winner = true;
    
    if(is_winner){
        return false;
    } else {
        for(int r = 0; r < SIZE_BOARDS; r++){
            for(int c = 0; c < SIZE_BOARDS; c++){
                if(boards[board_num].rows[r][c] != -1){
                    have_winner = false;
                }
            }
            if(have_winner){
                return true;
            }
        }
        for(int r = 0; r < SIZE_BOARDS; r++){
            for(int c = 0; c < SIZE_BOARDS; c++){
                if(boards[board_num].cols[r][c] != -1){
                    have_winner = false;
                }
            }
            if(have_winner){
                return true;
            }
        }
    }

}

void play_game(board boards[], ll_int drawn_num[]){
    bool have_winner;
    int i = 0;

    while(i < DRAWN_NUMBERS){
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
            if(check_board(boards, l)){

            }
        }
        i++;
    }
}

void print_rows(board boards[]){
    for(int i = 0; i < NUM_BOARDS; i++){
        printf("Board %d:\n\n", i);
        for(int r = 0; r < SIZE_BOARDS; r++){
            printf("Row %d: ", r);
            for(int c = 0; c < SIZE_BOARDS; c++){
                printf("%lld ", boards[i].rows[r][c]);
            }
            printf("\n");
        }
    }
}

void print_cols(board boards[]){
    for(int i = 0; i < NUM_BOARDS; i++){
        printf("Board %d:\n\n", i);
        for(int c = 0; c < SIZE_BOARDS; c++){
            printf("Column %d: ", c);
            for(int r = 0; r < SIZE_BOARDS; r++){
                printf("%lld ", boards[i].cols[c][r]);
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
