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
    int count=0;

    while ((c = fgetc(fp)) != EOF) {
        if (((c == ' ') || (c == '\t')) || (c == '\n')) {
            count += 1;
        }
    }

    fclose(fp);
    printf("%d\n", count);
    return 0;
}