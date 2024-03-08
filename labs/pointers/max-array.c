/* A program to store numbers in an array and compute their maximum.
 * This code illustrates the use of arrays within functions. 
 */

#include <stdio.h>

// number of elements to be processed in array
#define LENGTH 10

// Calculate and return the maximal number in an array
double find_max(double array[], int array_size) {
  // start with first array value
  double max = array[0];
  
  // compare maximum with previous values, updating as needed
  for (int j = 1; j < array_size; j++) {
    if (array[j] > max) {
      max = array[j];
    }
  }

  return max;
}

// Calculate and return the maximal number in an array
double find_max_pointer(double* array, int array_size) {
  // start with first array value
  double max = *array;
  
  // compare maximum with previous values, updating as needed
  for (int* j = array; j < (array + array_size); j++) {
    if (j > array) {
      max = *array;
    }
  }

  return max;
}

// Declare and initialize a list of numbers, printing them and their maximum
int main() {
  printf("Program to process real numbers.\n");
  
  // declare array of LENGTH values
  double numbers[LENGTH] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  
  double bigNumber = find_max_pointer(numbers, LENGTH);
  
  printf("The maximum of ");

  for (int i = 0; i < LENGTH; i++) {
    printf(" %5.2lf", numbers[i]);
  }
  printf("\n");
  
  printf("is %5.2lf\n", bigNumber);
  
  return 0;
}
