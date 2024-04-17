#include <stdlib.h>
#include <stdio.h>

int main(){


    int* arr = calloc(8, sizeof(int));
    if (arr == NULL) {
     perror("Failed to allocate memory");
     exit(EXIT_FAILURE);
    }
    for (int i=0; i<8; i++) {
     arr[i] = i;
    }
    free(arr);
    return 0;
}