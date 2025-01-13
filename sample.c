#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
  return read_file("/home/salazar/Documents/Contest/Ankitha enjoys finding.txt");
}

int read_file(const char *filename) {
    FILE* ptr = fopen(filename, "r");

    if (ptr == NULL) {
        printf("File cannot be opened.\n");
        return(-1);
    }

    char buff[BUFSIZE];

    while (fgets(buff, BUFSIZE, ptr) != NULL) {
        printf("%s", buff);
    }

    return 0;
}
