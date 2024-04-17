#include <stdio.h>
#include <stdlib.h>

int main(){
    int* p;
    int* q = (int*)malloc(sizeof(int));
    if (q == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
    }

    int x = 5;
    p = &x;
    *q = 100;
    *p = 200;
    int* w = q;
    p = (int*)malloc(sizeof(int));
    if (p == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
    }

    q = &x;

    printf("%d\n", *w);
    return 0;
}

