#ifndef BVERNAN_USEDFILE_H
#define BVERNAN_USEDFILE_H

#define T_OUTPUT 0
#define T_INPUT 1

typedef struct File
{
    int fd;
    unsigned char* block;
    long block_size;
    int type;
} File_t;

File_t *input_open_file(char *path, long block_size);

File_t *output_open_file(char *path, long block_size);

int read_next_block(File_t *file);

int write_current_block(File_t *file);

void close_file(File_t *file);

int isDirectory(const char *path);

#endif