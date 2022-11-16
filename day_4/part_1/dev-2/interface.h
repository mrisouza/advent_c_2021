#pragma once

typedef long long int ll_int;

typedef struct Board {
    ll_int rows[5][5];
    ll_int cols[5][5];
    bool winner;
} board;

void get_drawn_numbers(FILE* pfnums, ll_int drawn_num[]);
void init_boards(FILE* pfboards, board boards[]);
