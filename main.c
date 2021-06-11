#include <stdio.h>
#include "usedfile.h"
#include "keyfile.h"
#include "bvernan.h"

void print_usage(){
    printf("usage: bvernan keyfile inputfile outputfile\n");
}

int main(int argc, char** argv) {

    if (argc != 4) {
        print_usage();
        return 0;
    }

    Key_t *key = open_key_file(argv[1]);
    if (key == NULL){
        perror(argv[1]);
        return 1;
    }

    File_t *file = open_file(argv[2],argv[3],key->lenght);
    if (file == NULL){
        perror(argv[2]);
        return 1;
    }

    int encrypt_result = encrypt(file,key);

    close_file(file);
    free_key(key);

    if(encrypt_result == 0) printf("File encrypted succesfully!\n");

    return 0;
}