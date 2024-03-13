#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *sentence = argv[1]; // The sentence is the element index 1 of the input (also counting the ./program)
    char *word = argv[2]; // The word we want to search for is the third one, which has index 2
    int count = 0; // Initialize count to be 0

    // Pointer to track the current position in the sentence
    char *currentPosition = sentence;

    // Iterate over the sentence to find all occurrences of the word
    while ((currentPosition = strstr(currentPosition, word)) != NULL) {
        count++;
        currentPosition++; // Move pointer to continue searching
    }

    printf("The substring '%s' appears %d times.\n", word, count);

    return 0;

}