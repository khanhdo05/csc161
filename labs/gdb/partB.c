#include <stdio.h>
#include <stdbool.h>

#define LENGTH 100

int main() {
  printf("This program searches for primes using the seive of Eratosthenes\n");

  // Set up an array of booleans that record whether the index is prime
  bool is_prime[LENGTH];
  
  // Initialize the whole array to true
  for(int i=0; i<LENGTH; i++) {
    is_prime[i] = true;
  }

  // But 0 and 1 are not prime
  is_prime[0] = false;
  is_prime[1] = false;

  // Keep count of how many primes we find
  int count = LENGTH - 2;

  // Loop over possible factors
  for (int factor=2; factor<LENGTH; factor++) {
    // Loop over multiples of the current factor
    for (int multiple=factor; multiple < LENGTH; multiple += factor) {
      // If we previously thought this number was prime, stop counting it
      if (is_prime[multiple]) {
        count--;
      }

      // Mark the number as not prime
      is_prime[multiple] = false;
    }
  }

  // Print the results
  printf("Found %d primes:\n", count);
  for (int i=2; i<LENGTH; i++) {
    if (is_prime[i]) {
      printf("%d\n", i);
    }
  }
}
