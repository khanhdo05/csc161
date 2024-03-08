#include <stdio.h>

int main(void) {
        // Code for exercise 1:
    int a = 1;
    int b = 2;
    int* c = &a;
    int* d = &b;
    b++;
    //printf("a: %d, b: %d, *c: %d, *d: %d\n", a, b, *c, *d);
    // Code for exercise 2:
    *c = *c + 1;
    *d = *c + b;
    d = c;
    //printf("a: %d, b: %d, *c: %d, *d: %d\n", a, b, *c, *d);
    
    // Code for exercise 3:
    int* e = &a;
    int* f = e;
    int g = 99;
    (*e)++;
    e = &g;
    (*f)++;
    printf("a: %d, b: %d, *c: %d, *d: %d, *e: %d, *f: %d, g: %d\n",
        a, b, *c, *d, *e, *f, g);
    return 0;
}