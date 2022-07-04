#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main(int argc, char* argv[]){
    check_inputs(argc);
    FILE* pfile = read_content(argv[1]);
    sonar_sweep(pfile);
    return EXIT_SUCCESS;
}
