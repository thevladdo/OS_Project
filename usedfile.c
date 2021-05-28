#include <stdio.h>
#include "usedfile.h"
#include <fcntl.h>

File_t *input_open_file(char *path, long block_size){
    File_t *file = malloc(sizeof(File_t));
    file->block = malloc(block_size);
    file->type = T_INPUT;
    file->block_size = block_size;
    file->fd = open(path,O_RDONLY);
    read_next_block(file);
    return file;
}
