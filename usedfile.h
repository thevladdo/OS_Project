#ifndef BVERNAN_USEDFILE_H
#define BVERNAN_USEDFILE_H

typedef struct File
{
    unsigned char* block;
    long block_size;
    int fd_input;
    int fd_output;
} File_t;

/**
 * @brief Function that allocates the necessary memory and opens 
 *        the file by performing the appropriate checks
 * 
 * @param input_path Path of the input file
 * @param output_path Path of the output file
 * @param block_size Size of the blocks
 * @return File_t* Pointer to the file
 */
File_t *open_file(const char *input_path, const char *output_path, long block_size);


/**
 * @brief Function that reads the next block
 * 
 * @param file File from which the next block is read
 * @return int Number of bytes that have been read
 */
int read_next_block(File_t *file);


/**
 * @brief Function that write the current block
 * 
 * @param file File to write the current block to
 * @return int Number of bytes written
 */
int write_current_block(File_t *file);


/**
 * @brief Deallocates and close the file
 * 
 * @param file File that will be closed
 */
void close_file(File_t *file);


/**
 * @brief Check if one of the input files is a directory
 * 
 * @param path Path to analyze
 * @return int Error checking int
 */
int isDirectory(const char *path);

#endif