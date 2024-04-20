
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

typedef struct {
    GroceryItem *items;
    size_t size;
    size_t capacity;
} GroceryList;

void initialize_list(GroceryList *list) {
    list->items = malloc(sizeof(GroceryItem)); // Allocate memory for one item initially
    if (list->items == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    list->size = 0;
    list->capacity = 1; // Capacity is initially set to 1
}

void add_item(GroceryList *list, const char *name, int count) {
    // Allocate more memory if current space is not enough
    if (list->size >= list->capacity) {
        list->capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        list->items = realloc(list->items, list->capacity * sizeof(GroceryItem));
        // If realloc failed
        if (list->items == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }
    }

    // Increase the count of an item if the new item name match an already existed item
    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->items[i].name, name) == 0) {
            list->items[i].count += count;
            return;
        }
    }

    // Add new item to the list with its count
    strcpy(list->items[list->size].name, name);
    list->items[list->size].count = count;
    list->size++;
    return;
}


void print_list(const GroceryList *list) {
    if (list->size == 0) {
        printf("The list is empty.\n");
        return;
    } else {
        printf("Grocery List:\n");
        for (size_t i = 0; i < list->size; i++) {
            printf("\t%s: %d\n", list->items[i].name, list->items[i].count);
        }
        return;
    }
}

void lookup(const GroceryList *list, char *item_to_lookup) {
    for (size_t i = 0; i < list->size; i++) {
        // Iteratate through the list to find if there exists such item
        if (strcmp(list->items[i].name, item_to_lookup) == 0) {
            printf("You need %d %s.\n\n", list->items[i].count, list->items[i].name);
            return;
        }
    }

    // If not, print out a message
    printf("I didn't find %s on the list.\n\n", item_to_lookup);
    return;
}

void free_list(GroceryList *list) {
    free(list->items);
    list->items = NULL; // Avoid dangling pointer issues
    list->size = 0;
    list->capacity = 0;
}

int main(void) {
    GroceryList grocery_list;
    initialize_list(&grocery_list);

    char command_type[MAX_LENGTH_INPUT];

    while (1) {
        // Menu of Commands
        printf("\nWhat do you want to do? Type one of the following commands:\n"
               "\tadd: add an item\n"
               "\tlookup: look up an item\n"
               "\tprint: print the list\n"
               "\texit: exit the program\n");
        printf("\nCommand: ");
        
        fgets(command_type, MAX_LENGTH_INPUT, stdin);
        // Remove trailing newline if present
        char *newline = strchr(command_type, '\n');
        if (newline != NULL) *newline = '\0';

        // Handles 'exit' command
        if (strcmp(command_type, "exit") == 0) {
            printf("Happy grocery shopping!\n");
            break; // Immediately break out of this loop

        // Handles 'add' command
        } else if (strcmp(command_type, "add") == 0) {
            char item_input[MAX_LENGTH_INPUT];
            int quantity_input = 0;
            printf("What item would you like to add?\n");
            scanf("%s", item_input);
            printf("How many would you like?\n");

            // Check if input is a valid integer
            while ((scanf("%d", &quantity_input) != 1) || (quantity_input < 0)) {
                // Clear input buffer
                while (getchar() != '\n');
                printf("Invalid input for quantity. Please enter a non-negative integer.\n");
                printf("How many would you like?\n");
            }
            add_item(&grocery_list, item_input, quantity_input);

        // Handles 'print' command
        } else if (strcmp(command_type, "print") == 0) {
            print_list(&grocery_list);

        // Handles 'lookup' command
        } else if (strcmp(command_type, "lookup") == 0){
            char item_to_lookup[MAX_LENGTH_INPUT];
            printf("What item are you looking for?\n");
            scanf("%s", item_to_lookup);
            lookup(&grocery_list, item_to_lookup);

        // Handles invalid command
        } else {
            printf("Unrecognized command.\n\n");
        }
    }

    // Free allocated space of the dynamic array
    free_list(&grocery_list);

    return 0;
}
