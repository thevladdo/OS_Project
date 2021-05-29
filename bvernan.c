#include "bvernan.h"

void encrypt_block(unsigned char *block, long block_size, Key_t *key){
    for(int i=0; i<block_size ;i++){
        block[i] = block[i]^key->buffer[i];
    }
}

void encrypt(File_t *input, Key_t *key, File_t *output){
    while(read_next_block(input)!=0){
        output->block = input->block;
        output->block_size = input->block_size;
        encrypt_block(output->block,output->block_size,key);
        write_current_block(output);
    }
}