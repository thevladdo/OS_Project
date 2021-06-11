#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include "usedfile.h"

int isDirectory(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}

File_t *create_file(const char *input_path, const char *output_path, long block_size){
    File_t *file = malloc(sizeof(File_t));
    file->block = malloc(block_size);
    file->block_size = block_size;
    return file;
}

File_t *open_file(const char *input_path, const char *output_path, long block_size){
    File_t *file = create_file(input_path, output_path, block_size);
    file->fd_input = open(input_path,O_RDONLY);
    file->fd_output = open(output_path,O_CREAT | O_WRONLY,0644);
    if(isDirectory(input_path)){
        errno = EISDIR;
        return NULL;
    }
    if (file->fd_input < 0 || file->fd_output < 0) return NULL;
    return file;
}

int read_next_block(File_t *file){
    int readed_bytes = read(file->fd_input, file->block, file->block_size); 
    file->block_size = readed_bytes;
    return readed_bytes;
}

int write_current_block(File_t *file){
    int writed_bytes = write(file->fd_output, file->block, file->block_size);
    return writed_bytes;
}

void close_file(File_t *file){
    close(file->fd_input);
    close(file->fd_output);
    free(file->block);
    free(file);
}