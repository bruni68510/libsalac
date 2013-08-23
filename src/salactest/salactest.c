#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include <libsalac.h>

#define BUF_SIZE 1408

int main(int argc, char* argv[]) {
    int input_fd;
    int output_fd;

    ssize_t ret_in;
    ssize_t ret_out;

    char buffer[BUF_SIZE];

    char alac_buffer[BUF_SIZE];
    int alac_size = BUF_SIZE;

    if (argc != 3) {
        printf("Usage: salactest file.pcm file.alac");
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        perror("Could not open input file");
        return 2;
    }

    output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (output_fd == -1) {
        perror("Could not open output file");
        return 3;
    }

    init_encoder();
    while((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0) {
        memset(alac_buffer, 0, BUF_SIZE);
        encode_alac((unsigned char*) &buffer, (int) ret_in, (unsigned char*) &alac_buffer, alac_size); 
        ret_out = write(output_fd, &alac_buffer, (ssize_t) alac_size);     
        if (ret_out != alac_size) {
            perror("Write to ouput file failed");
            return 4;
        }
    }
    delete_encoder();
    close(input_fd);
    close(output_fd);

    return 0;
}
