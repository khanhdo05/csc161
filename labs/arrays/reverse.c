/**
 * Read a message from the user, then print it back in reverse.
 * 
 * \authors Khanh Do. and Zamijah Shakeur-Tompkins
 */

#include <stdio.h>

#define max_length 100

int main() {
  
  int len = 0;
  char ch;
  char message[max_length];

  printf("Enter a message: ");
  while ((len < max_length) && ((ch = getchar()) != '\n')) {
    message[len] = ch;
    len++;
  }

  printf("The reversed message is: ");
  for(int i = len - 1; i >= 0; i--) {
    printf("%c", message[i]);
  }
  printf("\n");
  
  return 0;
}