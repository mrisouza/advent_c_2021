#pragma once

typedef long long int ll_int;

#define SIZE_BOARDS 5
#define NUM_BOARDS 100
#define DRAWN_NUMBERS 100

typedef struct Board {
    ll_int rows[SIZE_BOARDS][SIZE_BOARDS];
    bool winner;
    ll_int last_number;
} board;

void get_drawn_numbers(FILE* pfnums, ll_int drawn_num[]);
void init_boards(FILE* pfboards, board boards[]);
void set_winners(board boards[]);
void print_board(board inst_board);
void init_game(board boards[], ll_int drawn_num[]);
void check_if_num_is_in_the_board(board* inst_board, ll_int num);
void print_answer(board inst_board, ll_int num);
