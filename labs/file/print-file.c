#include <stdio.h>

int main (int argc, char *argv[]) {

    if (argc == 1) {
        fprintf(stderr, "Error: didn't provide a file name.\n");
        return 0;
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("Failed to open file");
        return 0;
    }

    int c;

    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
    return 0;
}