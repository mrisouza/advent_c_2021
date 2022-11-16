#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "interface.h"

#define MAX 500

int main(int argc, char** argv){
    if(argc != 2){
        printf("few arguments...\n");
        exit(EXIT_FAILURE);
    }

    char* fname = argv[1];
    char filepath[MAX];
    strcpy(filepath, "./");
    strcat(filepath, fname);

    FILE* pfile = fopen(fname, "r");
    point arr_pts[2 * MAX];

    if(pfile == NULL){
        perror("error while opening file...\n");
        exit(EXIT_FAILURE);
    }
    
    ll_int num_points = store_points(arr_pts, pfile);
    ll_int max_x = get_max_coord(arr_pts, 'x', num_points);
    ll_int max_y = get_max_coord(arr_pts, 'y', num_points);

    point* grid = (point *) malloc(max_x * max_y * sizeof(point));

    create_grid(grid, max_x, max_y);
    //print_grid(grid, max_x, max_y);
    count_lines(grid, arr_pts, max_x, num_points);
    ll_int result = print_lines_in_grid(grid, max_x, max_y);

    printf("%lld\n", result);

    free(grid);
    fclose(pfile);
    return EXIT_SUCCESS;
}
