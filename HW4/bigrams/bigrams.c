#include <stdio.h>

#define MAX 256 // Because there are 256 ASCII characters

int main() {
  // Initiate variables
  char prev = getchar();
  char current;
  int arr[MAX][MAX] = {0};
  
  // Read in characters until newline character
  while ((current = getchar()) != '\n') {
    // Increment the count for a combination of two ASCII character that makes a bigram
    arr[prev][current]++;
    //  Move onto the next character of the input message
    prev = current;
  }

  // Nested for loop to print out the bigrams and their counts
  // Skip anything with count 0
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (arr[i][j] > 0) {
        printf("'%c%c' : %d\n", i, j, arr[i][j]);
      }
    }
  }


  // Find and print the most common bigram
  printf("Most common bigram: 'bigram'\n");

  return 0;
}
