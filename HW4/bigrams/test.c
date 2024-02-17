#include <stdio.h>

#define NUM_CHARS 256

int main() {
    // Initialize variables
    char prev_char = getchar();
    char current_char;
    int count_bigrams[NUM_CHARS][NUM_CHARS] = {0}; // Assuming ASCII characters

    // Read characters from input until encountering a newline
    while ((current_char = getchar()) != '\n') {
        // Update count for the current bigram
        count_bigrams[prev_char][current_char]++;
        // Update previous character
        prev_char = current_char;
    }

    // Print the counts of observed bigrams
    for (int i = 0; i < NUM_CHARS; i++) {
        for (int j = 0; j < NUM_CHARS; j++) {
            if (count_bigrams[i][j] > 0) {
                printf("'%c%c': %d\n", i, j, count_bigrams[i][j]);
            }
        }
    }

    // Find and print the most common bigram
    int max_count = 0;
    char most_common_bigram[2] = {'\0', '\0'};
    for (int i = 0; i < NUM_CHARS; i++) {
        for (int j = 0; j < NUM_CHARS; j++) {
            if (count_bigrams[i][j] > max_count) {
                max_count = count_bigrams[i][j];
                most_common_bigram[0] = i;
                most_common_bigram[1] = j;
            }
        }
    }
    if (most_common_bigram[0] != '\0' && most_common_bigram[1] != '\0') {
        printf("Most common bigram: '%c%c'\n", most_common_bigram[0], most_common_bigram[1]);
    } else {
        printf("No bigrams found\n");
    }

    return 0;
}
