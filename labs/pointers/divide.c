#include <stdio.h>

int divide(int dividend, int divisor, int* quotient, int* remainder) {
  // Check for division by zero
  if (divisor == 0) {
    return -1;
  }
  *quotient = dividend / divisor;
  *remainder = dividend % divisor;
  return 0;
}

int main(void) {
    int quotient;
    int remainder;
    if (divide(2, 0, &quotient, &remainder)) {
        printf("Error: attempted to divide by zero.\n");
    } else {
        printf("x/y is %d remainder %d.\n", quotient, remainder);
    }

    if (divide(2, 2, &quotient, &remainder)) {
        printf("Error: attempted to divide by zero.\n");
    } else {
        printf("x/y is %d remainder %d.\n", quotient, remainder);
    }

    if (divide(8, 5, &quotient, &remainder)) {
        printf("Error: attempted to divide by zero.\n");
    } else {
        printf("x/y is %d remainder %d.\n", quotient, remainder);
    }
}

