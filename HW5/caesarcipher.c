
/**
 * A program to encipher and decipher Caesar code.
 * 
 * \author Khanh Do
 */

#include <stdio.h>
#define MAX_LENGTH 100

// Helper functions declarations
char encodeChar(char ch, int key);
char decodeChar(char ch, int key);
void processMessage(char input[], char output[], int len, int key, char mode);

// Function to encode a character using the Caesar cipher
char encodeChar(char ch, int key) {
    return ((ch - 'a' + key) % 26) + 'a';
}

// Function to decode a character using the Caesar cipher
char decodeChar(char ch, int key) {
    return ((ch - 'a' - key + 26) % 26) + 'a';
}

// Function to encode or decode the input message based on mode
void processMessage(char input[], char output[], int len, int key, char mode) {
    for (int i = 0; i < len; i++) {
        if (mode == 'e') { // Encode
            output[i] = encodeChar(input[i], key);
        } else if (mode == 'd') { // Decode
            output[i] = decodeChar(input[i], key);
        } 
    }
    output[len] = '\0'; // Output is null-terminated
}

int main(void) {

    // Initialize variables
    int len = 0;
    char arr_message[MAX_LENGTH], temp_message[MAX_LENGTH];
    char ch, mes;

    // Print welcoming message
    printf("This program encrypts and decrypts messages using the Caesar Cipher\n");

    // Read in what mode user want to use
    printf("Type e to encode or d to decode a message: ");
    ch = getchar();
    getchar(); // Get the newline character
    // Check encode, decode, or invalid input
    if (ch != 'e' && ch != 'd') {
        printf("Valid options are 'e' to encode or 'd' to decode\n");
        return 1;
    }

    printf("Enter the string to %scode: ", ch == 'e' ? "en" : "de");

    // Read in the message
    while ((len < MAX_LENGTH - 1) && ((arr_message[len] = getchar()) != '\n')) {
        len++;
    }
    arr_message[len] = '\0'; // Null-terminate 

    for (int i = 0; arr_message[i] != '\0'; i++) {
        if (arr_message[i] < 'a' || arr_message[i] > 'z') { // Check if outside of 'a' to 'z'
            printf("Message should only contain alphabet characters, lowercase\n");
            return 1; 
        }
    }

    // For loop to print out the table
    for (int i = 0; i < 26; i++) {
        processMessage(arr_message, temp_message, len, i, ch);
        printf("n = %2d : %s\n", i, temp_message);
    }

    return 0;
}