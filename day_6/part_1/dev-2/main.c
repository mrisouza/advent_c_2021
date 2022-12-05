#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NO_INPUT "No input was given...\n"

int main(int argc, char** argv){
    if(argc != 3){
        printf(NO_INPUT);
        exit(EXIT_FAILURE);
    }
    char* filepath = argv[1];
    int days = atoi(argv[2]);
    u_int64_t stages[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    FILE* pfile = fopen(filepath, "r");
    int int_timer;
    
    while (fscanf(pfile, "%d,", &int_timer) != EOF){
        stages[int_timer]++;
    }

    u_int64_t l;
    int counter = 0;

    while(counter != days){
        l = 0;
        int s_0 = stages[0];
        int s_1 = stages[1];
        int s_2 = stages[2];
        int s_3 = stages[3];
        int s_4 = stages[4];
        int s_5 = stages[5];
        int s_6 = stages[6];
        int s_7 = stages[7];
        int s_8 = stages[8];

        stages[0] = s_1;
        stages[1] = s_2;
        stages[2] = s_3;
        stages[3] = s_4;
        stages[4] = s_5;
        stages[5] = s_6;
        stages[6] = (s_0 + s_7);
        stages[7] = s_8;
        stages[8] = s_0;
        
        for(int i = 0; i < 9; i++){
            l += stages[i];
        }
        counter++;
    }
    printf("%ld\n", l);
}
