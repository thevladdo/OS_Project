#include "bvernan.h"

void encrypt_block(File_t *file, Key_t *key){
    for(int i=0; i<file->block_size; i++){ 
        int key_position = (i+file->block_number)%key->lenght;
        file->block[i] = file->block[i]^key->buffer[key_position];
    }
}

int encrypt(File_t *file, Key_t *key){
    while(read_next_block(file) > 0){
        encrypt_block(file, key);
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