typedef struct Matrix {
    int* rows;
    int* columns;
} board;

FILE* open_file(const char* fname);
int get_num_random(char* line);
void file_handling(FILE* pfile);
