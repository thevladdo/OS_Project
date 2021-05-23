typedef struct Key
{
    unsigned char *buffer;
    int lenght;
} Key_t;

Key_t *open_file(char *path);

void free_key(Key_t *key);