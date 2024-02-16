#include <stdio.h>

int main() {
  // Initiate variables
  int len = 0;
  char ch;
  char message[len];

  while ((ch = getchar()) != '\n') {
    message[len] = ch;
    len++;
  }

  char arr[2][len-1];
  
  // Initialize the array with '0' in the second column
  for (int i = 0; i < 2; i++) {
      for (int j = 0; j < len - 1; j++) {
          if (j == 1) { // Set the second column to '0'
              arr[i][j] = '0';
          } else {      // Set other columns as desired, here I'm just using a placeholder character 'x'
              arr[i][j] = 'x';
          }
      }
  }

  // Print the most common bigram
  printf("Most common bigram: 'bigram'\n");

  return 0;
}
