
/**
 * A program to encipher and decipher Caesar message.
 * 
 * \author Khanh Do
 */

#include <stdio.h>
#define MAX_LENGTH 100

// Helper functions
// A function that check if input message is correct: lowercase, char, no symbol or num
char encodeChar(char ch, int key);
char decodeChar(char ch, int key);
// A function that either takes in a or b to do the encoding/decoding process to the whole message by returning the table
// A function that takes in the function that encode/decode the whole message to print out the table

// Function to encode a character using the Caesar cipher
char encodeChar(char ch, int key) {
    return ((ch - 'a' + key) % 26) + 'a';
}

// Function to decode a character using the Caesar cipher
char decodeChar(char ch, int key) {
    return ((ch - 'a' - key + 26) % 26) + 'a';
}

int main(void) {

    // Initialize variables
    char arr_codes[26] = {0};
    int len = 0;
    char ch;

    // Print welcoming message and read in user input
    printf("This program encrypts and decrypts messages using the Caesar Cipher\n");
    printf("Type e to encode or d to decode a message: ");
    ch = getchar();
    // Boolean to see if getchar() records an 'e' or a 'd' and run that following function.
    if (ch == 'e') {
        printf("Enter the string to encode: ");
    } else if (ch == 'd') {
        printf("Enter the string to decode: ");
    } else {
        printf("Valid options are 'e' to encode or 'd' to decode\n");
        return 0;
    }

    // For loop to print out the table
    printf("\n");
    for (int i = 0; i < 26; i++) {
        printf("n = %d: ", i);
        for (int j=0; j < len; j++) {
            printf("%c", arr_codes[j]);
        }
        printf("\n");
    }

    return 0;
}