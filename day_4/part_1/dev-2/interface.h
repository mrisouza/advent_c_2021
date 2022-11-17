#pragma once

typedef long long int ll_int;

#define MAX 5

typedef struct Board {
    ll_int rows[MAX][MAX];
    ll_int cols[MAX][MAX];
    bool winner;
} board;

void get_drawn_numbers(FILE* pfnums, ll_int drawn_num[]);
void init_boards(FILE* pfboards, board boards[]);
void init_game(board boards[]);
