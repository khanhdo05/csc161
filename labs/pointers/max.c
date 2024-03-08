

/**
 * Find the larger of two numbers and write the answer to result
 * \param m A number
 * \param n A number
 * \param Output location for the larger of m and n
 */
#include <stdio.h>
void set_max(int m, int n, int* result);

void set_max(int m, int n, int* result) {
    if (m > n) {
        *result = m;
    } else if (n > m) {
        *result = n;
    } else {
        *result = m;
    }
}

int main(void) {
    int answer;
    set_max(20, 10, &answer);
    printf("%d\n", answer);
}

