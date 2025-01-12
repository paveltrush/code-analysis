#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    char cmd[BUFSIZE];
    char* file_address = strdup(argv[1]);

    int limit_size = BUFSIZE - strlen("wc -c ");

    if(strlen(file_address) > limit_size){
        fprintf(stderr, "The file address value is too long.\n");
        return -1;
    }

    snprintf(cmd, BUFSIZE, "wc -c \"%s\"", file_address);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        perror("Error opening pipe");
        return -1;
    }

    char result[BUFSIZE];
    if (fgets(result, sizeof(result), pipe) != NULL) {
        printf("%s", result);
    } else {
        fprintf(stderr, "Error: Could not retrieve the file size.\n");
        return -1;
    }

    pclose(pipe);
}
