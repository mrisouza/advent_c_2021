#pragma once

typedef long long int ll_int;

#define SIZE_BOARDS 5
#define NUM_BOARDS 100
#define DRAWN_NUMBERS 100

typedef struct Board {
    ll_int rows[SIZE_BOARDS][SIZE_BOARDS];
    ll_int cols[SIZE_BOARDS][SIZE_BOARDS];
    bool winner;
    ll_int last_numer;
} board;

void get_drawn_numbers(FILE* pfnums, ll_int drawn_num[]);
void init_boards(FILE* pfboards, board boards[]);
void init_game(board boards[]);
void play_game(board boards[], ll_int drawn_num[]);
void print_boards(board boards[]);
void print_drawn_numbers(ll_int drawn_numbers[]);
bool check_all_row(board boards[], int num_board, int row);
void count_unmarkeds(board boards);
