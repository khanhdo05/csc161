#include "player_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Initialize an empty linked list tmakhat holds strings.
 * 
 * \param lst A pointer to a player_list_t that should be initialized.
 */
void player_list_init(player_list_t* lst) {
  // The list has no nodes, so head points to NULL
  lst->head = NULL;
  lst->length = 0;
}

/**
 * Initialize an empty linked list that holds strings.
 * 
 * \param tagged A pointer to a tagged_list_t that should be initialized.
 */
void tagged_list_init(tagged_list_t* tagged) {
  // The list has no nodes, so head points to NULL
  tagged->head = NULL;
  tagged->length = 0;
}

//Free all memory allocated as part of the provided list.
void player_list_destroy(player_list_t* lst) {
    player_node_t *curr;
    curr = lst->head;
    while (curr != NULL) {
        curr = curr->next;
        free(lst->head->value);
        free(lst->head);
        lst->head = curr;
    }
    lst->head = NULL;
    lst->length = 0;
}

//Free all memory allocated as part of the provided list.
void tagged_list_destroy(tagged_list_t* tagged) {
    player_node_t *curr;
    curr = tagged->head;
    while (curr != NULL) {
        curr = curr->next;
        free(tagged->head->value);
        free(tagged->head);
        tagged->head = curr;
    }
    tagged->head = NULL;
    tagged->length = 0;
}

// Add a player to the end of the given list. This function should take ownership of the memory pointed to by the name parameter.
void player_list_append(player_list_t* lst, char* name) {
    lst->length++;

    player_node_t *new_node, *curr;
    new_node = malloc(sizeof(player_node_t));
    if (new_node == NULL) {
        printf("Error: malloc failed.");
        exit(EXIT_FAILURE);
    }
    curr = lst->head;

    new_node->value = name;
    new_node->next = NULL;

    if (lst->head == NULL) {
        // If the list is empty, make new_node the head
        lst->head = new_node;
    } else {
        // Find the last node in the list
        while (curr->next != NULL) {
            curr = curr->next;
        }
        // Append new_node to the end of the list
        curr->next = new_node;
    }
}

// Add a player to the end of the given list. This function should take ownership of the memory pointed to by the name parameter.
void tagged_list_append(tagged_list_t* tagged, char* name) {
    tagged->length++;

    player_node_t *new_node, *curr;
    new_node = malloc(sizeof(player_node_t));
    if (new_node == NULL) {
        printf("Error: malloc failed.");
        exit(EXIT_FAILURE);
    }
    curr = tagged->head;

    new_node->value = strdup(name);
    new_node->next = NULL;

    if (tagged->head == NULL) {
        // If the list is empty, make new_node the head
        tagged->head = new_node;
    } else {
        // Find the last node in the list
        while (curr->next != NULL) {
            curr = curr->next;
        }
        // Append new_node to the end of the list
        curr->next = new_node;
    }
}

// Remove the player with the provided name from the list. Return true if a matching player was found and removed, or false otherwise.
bool player_list_remove(player_list_t* lst, tagged_list_t* tagged, char* name) {
    player_node_t *prev = NULL;
    player_node_t *curr = lst->head;

    // Traverse the list to find the node to remove
    while (curr != NULL && strcmp(curr->value, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    // When the player input is not found, return false
    if (curr == NULL) {
        return false;
    }

    // Update the pointers to remove the node from the list
    if (prev == NULL) {
        // If the node found is the head
        lst->head = curr->next;
    } else {
        // If the node found is in the middle
        prev->next = curr->next;
    }

    // Append the removed player to the tagged list
    tagged_list_append(tagged, curr->value);

    // Free the memory allocated for the removed player
    free(curr->value);
    free(curr);
    lst->length--;

    return true;
}

// Return the number of players in the given list.
size_t player_list_length(const player_list_t* lst) {
    return lst->length;
}

// Print the current list, interpreting it as the target ring. 
void print_as_target_ring(const player_list_t* lst) {
    if (lst->length == 0) {
        printf("There are no targets left.\n");
    } else if (lst->length == 1) {
        printf("%s is the final person remaining.\n", lst->head->value);
    } else {
        printf("Target Ring:\n");
        player_node_t *curr;
        curr = lst->head;
        while (curr->next != NULL) {
            printf("    %s is stalking %s\n", curr->value, curr->next->value);
            curr = curr->next;
        }
        if (curr->next == NULL) {
            printf("    %s is stalking %s\n", curr->value, lst->head->value);
        }
    }
}

// Print the current tagged list
void print_as_tagged_list(const tagged_list_t* tagged) {
    if (tagged->length == 0) {
        printf("No people have been tagged yet.\n");
    } else {
        printf("Tagged Ring:\n");
        player_node_t *curr;
        curr = tagged->head;
        while (curr != NULL) {
            printf("    %s\n", curr->value);
            curr = curr->next;
        }
    }
}