#include <stdio.h>
#include <stdlib.h>

void map(int (*f)(int), int *arr, int len);
int plus1(int num);

void map(int (*f)(int), int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int tempt = arr[i];
        arr[i] = f(tempt);
    }
}

int plus1(int num) {
    return ++num;
}

int makeNegative(int num) {
    return -num;
}

int main() {
    int arr[5] = {0,1,2,3,4};

    printf("Before map:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    map(plus1, arr, 5);

    printf("After map:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    map(makeNegative, arr, 5);
    
    printf("After map:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}