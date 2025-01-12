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

    snprintf(cmd, BUFSIZE, "wc -c \"%s\"", argv[1]);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        perror("popen failed");
        return -1;
    }

    char result[BUFSIZE];
    if (fgets(result, sizeof(result), pipe) != NULL) {
        printf("%s", result);
    } else {
        fprintf(stderr, "Error: Could not retrieve the file size.\n");
    }

    pclose(pipe);
    return 0;
}
