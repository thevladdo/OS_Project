#include <stdio.h>
#include <stdlib.h>
#include "usedfile.h"
#include "keyfile.h"


void encrypt(File_t *input, Key_t *key, File_t *output);
//prende i tre file
//richiamo block che me lo cifra
//riscrivo i file

void encrypt_block(unsigned char *block, long block_size, Key_t *key);
//prende il blocco, lo divido per byte e applico lo xor
