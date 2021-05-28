#include <stdio.h>
#include "keyfile.h"

int get_file_lenght(FILE *file){
    fseek(file, 0, SEEK_END);
    int lenght = ftell(file);
    rewind(file);
    return lenght;
}

Key_t *open_file(char *path){
    Key_t *key = malloc(sizeof(Key_t));
    FILE *file = fopen(path,"r");
    key->lenght = get_file_lenght(file);
    key->buffer = malloc(key->lenght);
    fread(key->buffer, key->lenght, 1, file);
    fclose(file);
    return key;
}

void free_key(Key_t *key){
    free(key->buffer);
    free(key);
}