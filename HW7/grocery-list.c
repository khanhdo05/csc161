
/**
 * A simple grocery list program. 
 * The program will use a dynamic array to keep track of items on the list, which include both a name and a count.
 * \author Khanh Do
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 128


int main(void) {
    char* command_type;

    printf("What do you want to do? Type one of the following commands:\n\tadd: add an item\n\tlookup: look up an item\n\tprint: print the list\n\texit: exit the program\n\n");
    printf("Command: ");
    scanf("%s", command_type);

    return 0;
}