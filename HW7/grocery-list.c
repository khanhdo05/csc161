
/**
 * A simple grocery list program. 
 * The program will use a dynamic array to keep track of items on the list, which include both a name and a count.
 * \author Khanh Do
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH_INPUT 128

typedef struct {
    char name[MAX_LENGTH_INPUT];
    int count;
} GroceryItem;

// add_command func that takes and returns a char pointer + an int pointer
void add_command(char * item_input, int * quantity_input) {
    printf("What item would you like to add?\n");
    scanf("%s", item_input);

    printf("How many would you like?\n");
    scanf("%d", quantity_input);
}

// use add_command to store stuff in a 2-d array or a struct

int main(void) {
    GroceryItem* grocery_list = NULL;
    size_t list_size = 0;
    size_t list_capacity = 0;

    char command_type[7];
    char item_input[MAX_LENGTH_INPUT];
    int quantity_input;

    printf("What do you want to do? Type one of the following commands:\n\tadd: add an item\n\tlookup: look up an item\n\tprint: print the list\n\texit: exit the program\n\n");
    printf("Command: ");
    scanf("%s", command_type);
    printf("%s\n", command_type);

    if (strcmp(command_type, "add") == 0) {
        add_command(item_input, &quantity_input);
    }

    if (strcmp(command_type, "exit") == 0) {
        return 0;
    }

    return 0;
}