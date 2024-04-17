#include <stdlib.h>
#include <stdio.h>

int main(){

    // MEMORY LEAKS IS WHEN WE DON"T FREE 
    int* arr = calloc(8, sizeof(int));
    if (arr == NULL) {
     perror("Failed to allocate memory");
     exit(EXIT_FAILURE);
    }
    for (int i=0; i<9; i++) { // HEAP BUFFER OVERRUNS: trying to read beyond malloc spae
     arr[i] = i;
    }
    free(arr);
    free(arr); // DOUBLE FREE
    // USE AFTER FREE: trying to use memory that has been freed
    for (int i=0; i<8; i++) { 
     arr[i] = 0;
    }
    return 0;
}