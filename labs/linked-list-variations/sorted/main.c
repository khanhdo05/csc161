#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_list.h"

/**
 * Check to see if a line of input matches a command followed by a singe string argument.
 * 
 * \param cmd The command to check against
 * \param line The line being checked
 * \returns NULL if there is no match, or a pointer to the argument if the command does match.
 */
const char* check_command(const char* cmd, const char* line) {
  // If the line doesn't begin with cmd, return an error
  if (strncmp(cmd, line, strlen(cmd)) != 0) return NULL;

  // Check for a space after the command
  if (line[strlen(cmd)] != ' ') {
    printf("Error: Missing argument.\n");
    return NULL;
  }

  // Make sure the argument isn't empty
  if (strlen(line) < strlen(cmd) + 2) {
    printf("Error: Empty argument.\n");
    return NULL;
  }

  // Return the argument
  return line + strlen(cmd) + 1;
}

void show_help() {
  printf("Commands:\n");
  printf("  help: show this message\n");
  printf("  insert <str>: insert a string at the front of the list\n");
  printf("  append <str>: append a string to the end of the list\n");
  printf("  count <str>: count the number of occurrences of a string in the list\n");
  printf("  remove <str>: remove the first occurrence of a string in the list\n");
  printf("  length: get the length of the list\n");
  printf("  print: print all strings in the list\n");
  printf("  exit: exit the program\n");
}

int main() {
  // Create a list and initialize it
  string_list_t lst;
  string_list_init(&lst);

  printf("Enter a command. Type \"help\" to see available options.\n");

  // Print a command prompt line:
  printf("> ");
  fflush(stdout);

  // Use getline to read commands from the user
  char* line = NULL;
  size_t line_capacity = 0;
  size_t line_length;
  while ((line_length = getline(&line, &line_capacity, stdin)) != -1) {
    // Remove the trailing newline from line by overwriting it with a null terminator
    line[line_length-1] = '\0';

    // A temporary string used for some command handling
    const char* arg;

    // Check for commands
    if (strcmp(line, "help") == 0) {
      // Show a help message
      show_help();

    } else if (strcmp(line, "length") == 0) {
      // Print the list length
      size_t len = string_list_length(&lst);
      printf("length = %lu\n", len);

    } else if (strcmp(line, "print") == 0) {
      // Print the list
      string_list_print(&lst);

    } else if ((arg = check_command("insert", line)) != NULL) {
      // Insert a new string
      // Use strdup because the list takes ownership of arg
      string_list_insert(&lst, strdup(arg));
    
    } else if ((arg = check_command("count", line)) != NULL) {
      // Count occurrences of a value in the list
      size_t count = string_list_count(&lst, arg);
      printf("Found %lu occurrence(s)\n", count);
    
    } else if ((arg = check_command("remove", line)) != NULL) {
      // Remove the first occurrence of a value in the list
      bool result = string_list_remove(&lst, arg);
      if (!result) {
        printf("Value was not found in the list.\n");
      }
    
    } else if (strcmp(line, "exit") == 0) {  
      // Exit the command loop
      break;
    
    } else {
      printf("Unrecognized command.\n");
      show_help();
    }

    // Print a command prompt line:
    printf("> ");
    fflush(stdout);
  }

  // Clean up after getline
  free(line);

  // Clean up the list
  string_list_destroy(&lst);

  return 0;
}
