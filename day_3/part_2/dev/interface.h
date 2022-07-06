typedef struct S_fcontent{
    char* content;
    int frequency_1;
    int frequency_0;
    int num_bits;
} fcontent;

void init(fcontent* f, FILE* pfile);
char bit_in_position(fcontent* f, int pos, bool is_oxygen);
void update_content(fcontent* f, int pos, char bit);
void remove_lines(fcontent* f, int pos, bool is_oxygen);

/* File handling */
FILE* open_file(const char* fname);
void close_file(FILE* pfile);
