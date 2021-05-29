#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "usedfile.h"

File_t *create_file(char *path, long block_size,int type){
    File_t *file = malloc(sizeof(File_t));
    file->block = NULL;
    file->block_size = block_size;
    file->type = type;
    return file;
}

File_t *input_open_file(char *path, long block_size){
    File_t *file = create_file(path,block_size,T_INPUT);
    file->block = malloc(block_size);
    file->fd = open(path,O_RDONLY);
    return file;
}

File_t *output_open_file(char *path, long block_size){
    File_t *file = create_file(path,block_size,T_OUTPUT);
    file->fd = open(path,O_WRONLY);
    return file;
}

void close_file(File_t *file){
    close(file->fd);
    if(file->type == T_INPUT) free(file->block);
    free(file);
}

int read_next_block(File_t *file){
    if (file->type != T_INPUT) return 0;
    int readed_bytes = read(file->fd, file->block, file->block_size); 
    file->block_size = readed_bytes;
    return readed_bytes;
}

int write_current_block(File_t *file){
    if (file->type != T_OUTPUT) return 0;
    int writed_bytes = write(file->fd, file->block, file->block_size);
    file->block = NULL;
    return writed_bytes;
}



