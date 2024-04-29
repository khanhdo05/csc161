#pragma once

#include <stdbool.h>
#include <stdlib.h>


// The type for a node in a string list
typedef struct player {
  char* value;
  struct player* next;
} player_t;

// A string list
typedef struct player_list {
  player_t* head;
  size_t length;
} player_list_t, tagged_list_t;

// Initialize an empty list. The lst parameter must point to usable memory that can hold a player_list_t.
void player_list_init(player_list_t* lst);

//Free all memory allocated as part of the provided list.
void player_list_destroy(player_list_t* lst);

//Free all memory allocated as part of the provided list.
void tagged_list_destroy(tagged_list_t* tagged);

// Add a player to the end of the given list. This function should take ownership of the memory pointed to by the name parameter.
void player_list_append(player_list_t* lst, char* name);

// Remove the player with the provided name from the list. Return true if a matching player was found and removed, or false otherwise.
bool player_list_remove(player_list_t* lst, tagged_list_t* tagged, char* name);

// Return the number of players in the given list.
size_t player_list_length(const player_list_t* lst);

// Print the current list, interpreting it as the target ring. 
void print_as_target_ring(const player_list_t* lst);

// Print the current tagged list
void print_as_tagged_list(const tagged_list_t* lst);