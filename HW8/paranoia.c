#include "player_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    // Create a list and initialize it
    player_list_t lst;
    player_list_init(&lst);

    tagged_list_t tagged;
    tagged_list_init(&tagged);

    char* line = NULL;
    size_t line_capacity = 0;
    size_t line_length;
    while ((line_length = getline(&line, &line_capacity, stdin)) != -1) {
        // Remove the trailing newline from line by overwriting it with a null terminator
        line[line_length-1] = '\0';

        // A temporary string used for some command handling
        const char* arg;

        // Check for commands
        if (strcmp(line, "\n") == 0) {
            break;
        } 
    }

    // Clean up after getline
    free(line);

    // Clean up the list
    player_list_destroy(&lst);

    return 0;
}