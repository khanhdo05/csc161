#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){


    char* str = calloc(14, sizeof(char));
    if (str == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
    }
    strcpy(str, "Hello");
    strcat(str, ", world.");
    printf("%s\n", str);

    free(str);
    return 0;
}