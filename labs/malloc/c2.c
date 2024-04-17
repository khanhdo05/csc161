#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAME_LENGTH 100

int main() {
  // First, we're going to generate a random number of names to ask for.
  // To do this well, we need to *seed* a pseudo-random number generator.
  srand(time(NULL));

  // Now generate a random number of names to ask for. We want 2–5.
  int num_names = (rand() % 4) + 2;

  // TODO: Allocate space for an array that holds `num_names` strings.
  // The result is a double pointer because it is an array of pointer values.
  char** names = calloc(num_names, sizeof(char*));

  // Ask the user to enter names:
  printf("Please enter %d names.\n", num_names);
  for (int i=0; i<num_names; i++) {
    // TODO: Allocate space for NAME_LENGTH characters
    names[i] = calloc(NAME_LENGTH+1, sizeof(char));

    // Ask the user for a name
    printf("Enter name %d: ", i+1);
    fflush(stdout); // Display the prompt without a newline

    // Read in the name
    fgets(names[i], NAME_LENGTH, stdin);
  }

  // Print the results:
  printf("You entered:\n");
  for (int i=0; i<num_names; i++) {
    printf("  %d: %s", i+1, names[i]);
    free(names[i]);
  }

  free(names);
  return 0;
}
