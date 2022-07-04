typedef struct S_fcontent{
    char* content;
    int* frequency_1;
    int* frequency_0;
    int num_bits;
} fcontent;

void init(fcontent* f, FILE* pfile);
void get_gamma_and_epsilon(fcontent* f);
void read_content(fcontent* f);

/* File handling */
FILE* open_file(const char* fname);
void close_file(FILE* pfile);
