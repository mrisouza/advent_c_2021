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
}

void set_winners(board boards[]){
    for(int i = 0; i < NUM_BOARDS; i++){
        boards[i].winner = false;
    }
}

void print_board(board inst_board){
    for(int r = 0; r < SIZE_BOARDS; r++){
        for(int c = 0; c < SIZE_BOARDS; c++){
            printf("%lld ", inst_board.rows[r][c]);
        }
        printf("\n");
    }
}

void check_if_num_is_in_the_board(board* inst_board, ll_int num){
    for(int r = 0; r < SIZE_BOARDS; r++){
        for(int c = 0; c < SIZE_BOARDS; c++){
            //printf("Comparing %lld == %lld\n", inst_board.rows[r][c], num);
            if(inst_board->rows[r][c] == num){
                //printf("Comparing %lld == %lld\n", inst_board->rows[r][c], num);
                inst_board->rows[r][c] = -1;
            }
        }
    }
}

bool check_if_row_is_filled(board* inst_board){
    bool is_row_filled;
    for(int r = 0; r < SIZE_BOARDS; r++){
        is_row_filled = true;
        for(int c = 0; c < SIZE_BOARDS; c++){
            if(inst_board->rows[r][c] != -1){
                is_row_filled = false;
            }
        }
        if(is_row_filled){
            return true;
        }
    }
    return is_row_filled;
}

bool check_if_col_is_filled(board* inst_board){
    bool is_col_filled;
    for(int c = 0; c < SIZE_BOARDS; c++){
        is_col_filled = true;
        for(int r = 0; r < SIZE_BOARDS; r++){
            if(inst_board->rows[r][c] != -1){
                is_col_filled = false;
            }
        }
        if(is_col_filled){
            return true;
        }
    }
    return is_col_filled;
}

void print_answer(board inst_board, ll_int num){
    ll_int total = 0;
    for(int r = 0; r < SIZE_BOARDS; r++){
        for(int c = 0; c < SIZE_BOARDS; c++){
            if(inst_board.rows[r][c] != -1){
                total += inst_board.rows[r][c];
            }
        }
    }
    printf("%lld\n", total * num);
}

void init_game(board boards[], ll_int drawn_num[]){
    bool has_winner = false;
    int i = 0;
    while(!has_winner && (i < DRAWN_NUMBERS)){
        ll_int num = drawn_num[i]; /* sort a number */
        for(int b = 0; b < NUM_BOARDS; b++){
            check_if_num_is_in_the_board(&boards[b], num);
            bool row_is_filled = check_if_row_is_filled(&boards[b]);
            bool col_is_filled = check_if_col_is_filled(&boards[b]);
            bool is_row_or_col_filled = row_is_filled || col_is_filled;
            if(is_row_or_col_filled){
                has_winner = true;
                print_answer(boards[b], num);
            }
        }
        i++;
    }
}
