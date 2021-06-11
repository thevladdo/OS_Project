#ifndef BVERNAN_KEYFILE_H
#define BVERNAN_KEYFILE_H

typedef struct Key{
    unsigned char *buffer;
    int lenght;
} Key_t;

/**
 * @brief Allocating memory and opening the file that will be used as the key
 * 
 * @param path Path of the file
 * @return Key_t* Pointer to the key file
 */
Key_t *open_key_file(char *path);


/**
 * @brief Deallocation of the memory allocated in the previous function
 * 
 * @param key The file used as the key
 */
void free_key(Key_t *key);

#endif 