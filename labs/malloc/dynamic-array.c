#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Creating a dynamic array.\n");

  // Create variables to track the array
  int* data = malloc(1*sizeof(int));

  // Exercise D.2: Allocate space in the array
  // TODO: use realloc to request space for three integers in the array
  data = realloc(data, 3*sizeof(int));
  int capacity = 3;

  // Fill in some values:
  data[0] = 151;
  data[1] = 161;
  data[2] = 207;

  // Print the array:
  printf("My CS major:\n");
  for(int i=0; i<capacity; i++) {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.3: Expand the array
  // TODO: expand the array to hold ten values
  data = realloc(data, 10*sizeof(int));
  capacity = 10;
  
  // Fill in more values
  data[3] = 208;
  data[4] = 213;
  data[5] = 261;
  data[6] = 301;
  data[7] = 324;
  data[8] = 341;
  data[9] = 395;

  // Print the array again to show that the original three values were preserved:
  printf("My CS major:\n");
  for(int i=0; i<capacity; i++) {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.4: Shrink the array
  // TODO: use realloc to shrink the array so it only holds nine values
  data = realloc(data, 9*sizeof(int));
  capacity = 9;

  // Print the array again:
  printf("My CS major:\n");
  for(int i=0; i<capacity; i++) {
    printf("  CSC %d\n", data[i]);
  }
  printf("\n");

  // Exercise D.5: Free the array
  // TODO: free the memory allocated to hold the array
  free(data);

  printf("All done.\n");
}
