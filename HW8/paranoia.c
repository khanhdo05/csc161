#include "player_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* check_for_name(const char* line);

char* check_for_name(const char* line) {
    // Make sure the argument isn't empty
    if (strlen(line) <= 1) {
        printf("Error: Empty name.\n");
        return NULL;
    }

    // Return the name
    return strdup(line);
}

int main(void) {
    // Create a list and initialize it
    player_list_t lst;
    player_list_init(&lst);

    tagged_list_t tagged;
    tagged_list_init(&tagged);

    printf("Enter a player's name (press enter to begin game): ");

    char* line = NULL;
    size_t line_capacity = 0;
    size_t line_length;
    
    while ((line_length = getline(&line, &line_capacity, stdin)) != -1) {
        // Remove the trailing newline from line by overwriting it with a null terminator
        line[line_length-1] = '\0';

        // A temporary string used for some command handling
        const char* arg;

        // Check if the line is empty (i.e., user pressed enter without entering a name)
        if (strcmp(line, "") == 0) {
            break; // Exit the loop if an empty line is entered
        }
        // Check for a name
        char* name = check_for_name(line);
        if (name != NULL) {
            // Add the entered name to the player list
            player_list_append(&lst, name);

            // Prompt for another player's name
            printf("Enter another player's name: ");
        }
    }

    print_as_target_ring(&lst);

    // Clean up after getline
    free(line);

    // Clean up the list
    player_list_destroy(&lst);
    tagged_list_destroy(&tagged);

    return 0;
}