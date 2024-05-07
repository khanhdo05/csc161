#include "player_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* check_for_name(const char* line);

char* check_for_name(const char* line) {
    // Make sure the argument isn't empty
    if (strlen(line) <= 1) {
        printf("Error: Empty name. Please enter a name.\n");
        return NULL;
    }

    // Return the name
    return strdup(line);
}

int main(void) {
    // Create a list for the target list and initialize it
    player_list_t lst;
    player_list_init(&lst);

    // Create a list for the tagged list and initializa it
    tagged_list_t tagged;
    tagged_list_init(&tagged);

    printf("Enter a player's name (press enter to begin game): ");

    char* line = NULL;
    size_t line_capacity = 0;
    ssize_t line_length;
    
    // Handle user's input of names at the beginning of the game
    while ((line_length = getline(&line, &line_capacity, stdin)) != -1) {
        // Remove the trailing newline from line by overwriting it with a null terminator
        line[line_length-1] = '\0';

        // A temporary string used for some command handling
        const char *arg;

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

    // Initial print of the ring
    print_as_target_ring(&lst);
    printf("No people have been tagged yet.\n");

    // Repeatedly play rounds of Paranoia with the user
    while (player_list_length(&lst) > 1) {
        printf("\nThere are %zu people left.\n", player_list_length(&lst));
        printf("Enter a target: ");

        // Read the target input
        ssize_t line_length = getline(&line, &line_capacity, stdin);

        // Check for input errors or end of file
        if (line_length == -1) {
            // Handle input error or end of file
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Remove the trailing newline from line by overwriting it with a null terminator
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[line_length - 1] = '\0';
        }

        // Check if the line is empty (i.e., user pressed enter without entering a name)
        if (strcmp(line, "") == 0) {
            // Skip processing and continue to the next iteration
            continue;
        }

        // Check for a target
        char* target = check_for_name(line);
        if (target != NULL) {
            // Remove the target player from the list
            bool removed = player_list_remove(&lst, &tagged, target);
            if (!removed) {
                // Handle case where the target is not found
                printf("%s is not a target.\n", target);
            }

            // Print the new target ring
            print_as_target_ring(&lst);

            // Print the tagged list
            print_as_tagged_list(&tagged);
            
        }

        // Free memory allocated for target
        free(target);
    }

    // Check if there is only one person left in the game
    if (player_list_length(&lst) == 1) {
        printf("The winner is: %s\n", lst.head->value);
    }

    // Clean up after getline
    free(line);

    // Clean up the list
    player_list_destroy(&lst);
    tagged_list_destroy(&tagged);

    return 0;
}