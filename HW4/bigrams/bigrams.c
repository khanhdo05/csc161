#include <stdio.h>

#define MAX 256 // Because there are 256 ASCII characters

int main() {
  // Initiate variables
  char prev = getchar();
  char current;
  int count[MAX][MAX] = {0}; // 256x256 matrix to record count of combinations of 2 ASCII characters
  
  // Read in characters until newline character
  while ((current = getchar()) != '\n') {
    // Increment the count for a combination of two ASCII character that makes a bigram
    count[prev][current]++;
    //  Move onto the next character of the input message
    prev = current;
  }

  // Nested for-loop to print out the bigrams and their counts
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      // Skip anything with count 0
      if (count[i][j] > 0) {
        printf("'%c%c': %d\n", i, j, count[i][j]); // i and j are integers, when printed out as characters, becomes the actual characters from the input.
      }
    }
  }

  // Find and print the most common bigram
  int highest_count = 0;
  int most_common_bigram_row;
  int most_common_bigram_col;
  // Nested for-loop to find the highest count and its corresponding i, j
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (count[i][j] > highest_count) {
        highest_count = count[i][j];
        most_common_bigram_row = i;
        most_common_bigram_col = j;
      }
    }
  }
  printf("Most common bigram:'%c%c'\n", most_common_bigram_row, most_common_bigram_col);

  return 0;
}
