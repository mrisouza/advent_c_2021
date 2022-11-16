#pragma once

typedef long long int ll_int;

typedef struct Point{
    ll_int x;
    ll_int y;
    /* data */
    ll_int num_lines;
} point;

ll_int store_points(point arr_pts[], FILE* pfile);
ll_int get_max_coord(point arr_pts[], char coord, ll_int total_el);
void create_grid(point grid[], ll_int max_x, ll_int max_y);
void print_grid(point grid[], ll_int max_x, ll_int max_y);
void count_lines(point grid[], point arr_pts[], ll_int max_x, ll_int total_el);
ll_int print_lines_in_grid(point grid[], ll_int max_x, ll_int max_y);
