#include "string_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Initialize an empty linked list that holds strings.
 * 
 * \param lst A pointer to a string_list_t that should be initialized.
 */
void string_list_init(string_list_t* lst) {
  // The list has no nodes, so head points to NULL
  lst->head = NULL;
  lst->length = 0;
}

/**
 * Destroy a linked list that holds strings.
 * 
 * \param lst A pointer to an initialized string_list_t that should be destroyed.
 */
void string_list_destroy(string_list_t* lst) {
  string_node_t *curr;
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

/**
 * Add a string to the front of a string list.
 * 
 * \param lst A pointer to an initialized string list. The new value is added to the front of this
 *            list. This function does NOT take ownership of lst.
 * \param str A heap-allocated string that should be inserted into the list. This function takes 
 *            ownership of str, and will free the underlying memory in string_list_destroy.
 */
void string_list_insert(string_list_t* lst, char* str) {
  lst->length++;
  string_node_t *new_node, *curr, *prev;
  new_node = malloc(sizeof(string_node_t));
  if (new_node == NULL) {
    printf("Error: malloc failed.");
    exit(EXIT_FAILURE);
  }
  new_node->value= str;

  curr = lst->head;
  prev = NULL;

  while ((curr != NULL) && (strcmp(curr->value, str) <= 0)) {
    prev = curr;
    curr = curr->next;
  }

  if (prev == NULL) {
    new_node->next = lst->head;
    lst->head = new_node;
    return;
  } else if (curr == NULL) {
      prev->next = new_node;
      new_node->next = NULL;
      return;
  }

  prev->next = new_node;
  new_node->next = curr;

  return;
}

/**
 * Add a string to the end of a string list.
 * 
 * \param lst A pointer to an initialized string list. The new value is added to the back of this
 *            list. This function does NOT take ownership of lst.
 * \param str A heap-allocated string that should be appended to the list. This function takes 
 *            ownership of str, and will free the underlying memory in string_list_destroy.
 */
void string_list_append(string_list_t* lst, char* str) {
  lst->length++;
  string_node_t *new_node, *curr;
  new_node = malloc(sizeof(string_node_t));
  if (new_node == NULL) {
    printf("Error: malloc failed.");
    exit(EXIT_FAILURE);
  }
  curr = lst->head;
  new_node->value = str;
  new_node->next = NULL;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
}

/**
 * Count the number of times a value appears in the given list.
 * 
 * \param lst A pointer to an initialized string list.
 * \param str Count the number of times a value matching this string appears in the list.
 * \returns the number of times str was found in lst
 */
size_t string_list_count(const string_list_t* lst, const char* str) {
  int count = 0;
  string_node_t *curr;
  curr = lst->head;
  while (curr != NULL) {
    if (strcmp(curr->value, str) == 0) {
      count += 1;
    }
    curr = curr->next;
  }
  return count;
}

/**
 * Remove a string from the list.
 * 
 * \param lst A pointer to an initialized string list. The first matching occurrence of str in this 
 *            list will be removed.
 * \param str The first exact match of this string should be removed from the list.
 * \returns true if the value was found and removed, and false otherwise
 */
bool string_list_remove(string_list_t* lst, const char* str) {
    string_node_t *prev = NULL;
    string_node_t *curr = lst->head;

    // Traverse the list to find the node to remove
    while (curr != NULL && strcmp(curr->value, str) != 0) {
        prev = curr;
        curr = curr->next;
    }

    // When the str input is not found, return false
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

    free(curr->value);
    free(curr);
    lst->length--;

    return true;
}


/**
 * Calculate the length of a string list
 * 
 * \param lst A pointer to an initialized string list.
 * \returns the length of the list
 */
size_t string_list_length(const string_list_t* lst) {
  return lst->length;
}

/**
 * Print the elements of a string list, one per line.
 * 
 * \param lst A pointer to an initialized string list that should be printed.
 */
void string_list_print(const string_list_t* lst) {
  string_node_t *curr;
  curr = lst->head;
  while (curr != NULL) {
    printf("%s\n", curr->value);
    curr = curr->next;
  }
}
