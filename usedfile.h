typedef struct File
{
    int fd; //filedescriptor per leggere il file
    unsigned char* block;
    //int position; //per capire a che posizione del file siamo arrivati
} File_t;

File_t *input_open_file(char *path);

File_t *output_open_file(char *path);

void read_next_block(File_t *file);

void write_current_block(File_t *file);

void close_file(File_t *file);