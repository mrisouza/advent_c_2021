#include <stdio.h>
#include <stdlib.h>

#include "file_handler.h"
#include "input_handler.h"

int main(int argc, char** argv){
    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    FILE* pfile = get_file_pointer(argv[1]);
    int num_entries = count_entries(pfile);
    int hor_pos[num_entries];
    get_hor_position(hor_pos, pfile);
    int minimal = get_lower_cost(hor_pos, num_entries);
    printf("%d\n", minimal);
    fclose(pfile);
    return EXIT_SUCCESS;
}
