/**
 * Read a message from the user, then print it back in reverse.
 * 
 * \authors Khanh Do. and Zamijah Shakeur-Tompkins
 */

#include <stdio.h>

int main() {
  
  int len = 0;
  char ch;
  int max_length;
  printf("Enter max message length: ");
  scanf("%d", &max_length);
  char message[max_length];

  // Check for and discard newline character if present
  if ((ch = getchar()) == '\n') {
    ch = getchar(); // Discard the newline character
  }

  printf("Enter a message: ");
  while ((len < max_length) && ((ch = getchar()) != '\n')) {
    char message[len] = ch;
    len++;
  }

  printf("The reversed message is: ");
  for(int i = len - 1; i >= 0; i--) {
    printf("%c", message[i]);
  }
  printf("\n");
  
  return 0;
}