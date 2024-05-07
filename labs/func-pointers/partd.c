#include <stdio.h>
#include <stdlib.h>


void map(int (*f)(int), int *arr, int len);
int plus1(int num);
int makeNegative(int num);

// map takes in a function, array and array length
void map(int (*f)(int), int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int tempt = arr[i];
        arr[i] = f(tempt);
    }
}

// Testing func: plus 1 to a number
int plus1(int num) {
    return ++num;
}

// Testing func: make the number negative
int makeNegative(int num) {
    return -num;
}

int main() {
    // Initial array
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