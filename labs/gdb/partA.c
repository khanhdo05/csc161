#include <stdio.h>

#define ERROR -999

// Read a decimal number
int term() {
  int value = 0;
  int digits = 0;
  
  // Read in digits
  while (1) {
    char c = getchar();
    // If we found a number, add it on to the value
    if (c >= '0' && c <= '9') {
      digits++;
      value = value * 10 + (c - '0');
    } else {
      // Put the last character back on the input
      ungetc(c, stdin);

      // Check to see if we read at least one digit
      if (digits == 0) {
        return ERROR;
      } else {
        return value;
      }
    }
  }
}

// Read an expression
int expr() {
  // Read the left hand side
  int lhs = term();
  if (lhs == ERROR) return ERROR;

  // Read the operator
  char c = getchar();
  if (c == '\n' || c == EOF) {
    return lhs;
  } else if (c != '+' && c != '-') {
    return ERROR;
  }

  // Read the right hand side
  int rhs = expr();
  if (rhs == ERROR) return ERROR;

  // Combine the two sides with the given operator
  if (c == '+') {
    return lhs + rhs;
  } else if (c == '-') {
    return lhs - rhs;
  } else {
    return ERROR;
  }
}

int main() {
  printf("Welcome to the broken calculator program!\n");
  printf("This program gives (sometimes incorrect) answers to basic addition and subtraction problems.\n\n");
  printf("Enter an expression with +, -, and decimal numbers (no spaces).\n");

  // Read and evaluate an expression
  int result = expr();
  if (result == ERROR) {
    printf("Invalid input.\n");
  } else {
    printf("=%d\n", result);
  }

  return 0;
}
