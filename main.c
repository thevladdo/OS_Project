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

    File_t *input = input_open_file(argv[2],key->lenght);

    File_t *output = output_open_file(argv[3],key->lenght);

    encrypt(input,key,output);

    close_file(input);
    close_file(output);
    free_key(key);

    printf("File encrypted succesfully!\n");

    return 0;
}