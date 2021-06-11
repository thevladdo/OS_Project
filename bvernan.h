#ifndef BVERNAN_BVERNAN_H
#define BVERNAN_BVERNAN_H

#include <stdio.h>
#include <stdlib.h>
#include "usedfile.h"
#include "keyfile.h"

/**
 * @brief Function that encrypts and decripts files
 * 
 * @param file File that will be used for encrypt
 * @param key File used as key to encrypt and decrypt the input file
 * @return int Control int
 */
int encrypt(File_t *file, Key_t *key);

/**
 * @brief Function that divides the input file into blocks, 
 *        encrypts them one by one and then reassembles them 
 *        in the output file
 * 
 * @param block Block that will be encrypted
 * @param block_size Size of the block that will be encrypted
 * @param key File used as key to encrypt and decrypt
 */
void encrypt_block(unsigned char *block, long block_size, Key_t *key);

#endif