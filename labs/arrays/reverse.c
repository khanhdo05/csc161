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
  while (ch != '\n') {
    ch = getchar();
    message[len] = ch;
    len++;
  }

  for(int i = 0; i < len; i++) {
    printf("%s", &message[i]);
  }

  return 0;
}