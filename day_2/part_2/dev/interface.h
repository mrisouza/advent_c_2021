typedef struct S_position{
    int hor;
    int depth;
    int aim;
} position;

void init_position(position* p);
void move_submarine(const char* command, int value, position* p);
void print_position(position* p);
void multiply_coordinates(position* p);

/* File handling */
FILE* open_file(const char* fname);
void close_file(FILE* pfile);
void treat_file(FILE* pfile, position* p);
void get_and_execute_command(char* line, position* p);
