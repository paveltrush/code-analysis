#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define F_OK 0

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    char* file_address = strdup(argv[1]);

    int limit_size = BUFSIZE - strlen("wc -c ");

    if(strlen(file_address) > limit_size){
        fprintf(stderr, "The file address value is too long.\n");
        return -1;
    }

    if (access(file_address, F_OK) != 0) {
        printf("The file '%s' doesn't exists.\n", file_address);
    }

    char *cmd[] = {"wc", "-c", file_address, NULL};
    execvp(cmd[0], cmd);

    perror("execvp failed");
    return -1;
}
