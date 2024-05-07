#include <stdio.h>



int sum(int (*f)(int), int start, int end){
    int result = 0;
    for (int i = start; i <= end; i++) 
        result += f(i);
    return result;
}

int g1(int num) {
    return num*num;
}

int g2(int num) {
    return --num;
}

int main (void) {
    printf("%d\n", sum(g1, 1, 4));
    printf("%d\n", sum(g2, 1, 4));
    return 0;
}