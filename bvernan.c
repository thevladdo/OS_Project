#include "bvernan.h"

void encrypt_block(unsigned char *block, long block_size, Key_t *key){
    for(int i=0; i<block_size ;i++){
        block[i] = block[i]^key->buffer[i];
    }
}

int encrypt(File_t *file, Key_t *key){
    while(read_next_block(file) > 0){
        encrypt_block(file->block, file->block_size, key);
        int result = write_current_block(file);
        if (result <= 0){
            perror("writing block!");
            return -1;
        }
    }
    if(file->block_size == -1){
        perror("reading block!");
        return -1;
    }
    return 0;
}