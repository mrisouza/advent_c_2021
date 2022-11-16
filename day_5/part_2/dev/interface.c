#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "interface.h"

ll_int store_points(point arr_pts[], FILE* pfile){
    point p_1, p_2;
    ll_int i = 0;

    while(fscanf(pfile, "%lld,%lld -> %lld,%lld", &p_1.x, &p_1.y, &p_2.x, &p_2.y) != EOF){
        arr_pts[i] = p_1;
        arr_pts[i+1] = p_2;
        i += 2;
    }
    return i;
}

ll_int get_max_coord(point arr_pts[], char coord, ll_int total_el){
    ll_int maximum = -1000;
    
    for(ll_int i = 0; i < total_el; i++){
        if(coord == 'x'){
            if(arr_pts[i].x > maximum){
                maximum = arr_pts[i].x;
            }
        }
        if(coord == 'y'){
            if(arr_pts[i].y > maximum){
                maximum = arr_pts[i].y;
            }
        }
    }
    return maximum + 1;
}

void create_grid(point grid[], ll_int max_x, ll_int max_y){
    /* form i*max_y + j*/
    for(ll_int i = 0; i < max_x; i++){
        for(ll_int j = 0; j < max_y; j++){
            point p;
            p.x = i;
            p.y = j;
            p.num_lines = 0;
            grid[i * max_x + j] = p;
        }
    }
}

void print_grid(point grid[], ll_int max_x, ll_int max_y){
    for(ll_int i = 0; i < max_x; i++){
        for(ll_int j = 0; j < max_y; j++){
            printf("(%lld, %lld)\t", grid[i * max_x + j].x, grid[i * max_x + j].y);
        }
        printf("\n");
    }
}

void count_lines(point grid[], point arr_pts[], ll_int max_x, ll_int total_el){
    for(ll_int k = 0; k < total_el - 1; k += 2){

        ll_int x_1 = arr_pts[k].x;
        ll_int y_1 = arr_pts[k].y;
        ll_int x_2 = arr_pts[k+1].x;
        ll_int y_2 = arr_pts[k+1].y;

        if((x_1 == x_2) && (y_1 != y_2)){
            /* make y_2 > y_1 always */
            if(y_1 > y_2){
                ll_int tmp = y_2;
                y_2 = y_1;
                y_1 = tmp;
            }
            while(y_1 <= y_2){
                grid[x_1 * max_x + y_1].num_lines++;
                y_1++;
            }
        }
        if((x_1 != x_2) && (y_1 == y_2)){
            /* make x_2 > x_1 always */
            if(x_1 > x_2){
                ll_int tmp = x_2;
                x_2 = x_1;
                x_1 = tmp;
            }
            while(x_1 <= x_2){
                grid[x_1 * max_x + y_1].num_lines++;
                x_1++;
            }
        }
        if((x_1 == x_2) && (y_1 == y_2)){
            if(x_1 > x_2){
                ll_int tmp = x_2;
                x_2 = x_1;
                x_1 = tmp;
            }
            while(x_1 <= x_2){
                grid[x_1 * max_x + x_1].num_lines++;
                x_1++;
            }
        }
        if((x_1 != x_2) && (y_1 != y_2)){
            if(x_1 > x_2){
                ll_int tmp = x_2;
                x_2 = x_1;
                x_1 = tmp;
                ll_int tmp_2 = y_1;
                y_1 = y_2;
                y_2 = tmp_2;
            }
            if(y_1 < y_2){
                while(y_1 <= y_2){
                    grid[x_1 * max_x + y_1].num_lines++;
                    x_1++;
                    y_1++;
                }
            } else {
                while(y_1 >= y_2){
                    grid[x_1 * max_x + y_1].num_lines++;
                    x_1++;
                    y_1--;
                }
            }
        }
    }
}

ll_int print_lines_in_grid(point grid[], ll_int max_x, ll_int max_y){
    ll_int total = 0;
    for(ll_int j = 0; j < max_y; j++){
        for(ll_int i = 0; i < max_x; i++){
            if(grid[i * max_x + j].num_lines == 0){
                //printf(".");
                continue;
            } else {
                //printf("%lld", grid[i*max_x + j].num_lines);
                if(grid[i*max_x + j].num_lines >= 2){
                    total++;
                }
            }
        }
        //printf("\n");
    }
    return total;
}
