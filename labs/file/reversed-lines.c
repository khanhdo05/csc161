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

    FILE *nf;
    nf = fopen("reversed.txt", "w");

    int c;

    while ((c = fgetc(fp)) != EOF) {
        char arr[1024];
        while (c != '\n') {
            for (int i=1024; i >= 0; i--) {
                if (arr[i] != 0) {
                    arr[i] = c;
                }
            }
        }
        
    }

    fclose(fp);
    fclose(nf)
    return 0;
}