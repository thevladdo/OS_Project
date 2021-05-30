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

    Key_t *key = open_file(argv[1]);
    if (key == NULL){
        perror(argv[1]);
        return 1;
    }

    File_t *input = input_open_file(argv[2],key->lenght);
    if (input == NULL){
        perror(argv[2]);
        return 1;
    }

    File_t *output = output_open_file(argv[3],key->lenght);
    if (output == NULL){
        perror(argv[3]);
        return 1;
    }

    encrypt(input,key,output);

    close_file(input);
    close_file(output);
    free_key(key);

    printf("File encrypted succesfully!\n");

    return 0;
}