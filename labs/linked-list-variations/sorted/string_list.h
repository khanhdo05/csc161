#pragma once

#include <stdbool.h>
#include <stdlib.h>

/// The type for a node in a string list
typedef struct string_node {
  char* value;
  struct string_node* next;
} string_node_t;

/// A string list
typedef struct string_list {
  string_node_t* head;
} string_list_t;

/// Initialize an empty linked list that holds strings
void string_list_init(string_list_t* lst);

/// Destroy a linked list that holds strings
void string_list_destroy(string_list_t* lst);

/// Add a string to the front of a string list.
void string_list_insert(string_list_t* lst, char* str);

/// Add a string to the end of a string list
void string_list_append(string_list_t* lst, char* str);

/// Count the number of times a value appears in the given list
size_t string_list_count(const string_list_t* lst, const char* str);

/// Remove a string from the list
bool string_list_remove(string_list_t* lst, const char* str);

/// Calculate the length of a string list
size_t string_list_length(const string_list_t* lst);

/// Print the elements of a string list, one per line
void string_list_print(const string_list_t* lst);
