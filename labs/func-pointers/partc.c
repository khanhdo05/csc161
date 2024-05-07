#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void printProfits();
void printGreetings();
void printBest();
void printRefunds();
void printMusic();
void execute_command();

typedef struct {
  char* cmd_name;
  void (*cmd_pointer)();
} command_t;

command_t print_cmds[] = {
    {"profits", printProfits},
    {"greetings", printGreetings},
    {"best", printBest},
    {"refunds", printRefunds},
    {"music", printMusic} 
};

void execute_command(const char* cmd) {
    int len = sizeof(print_cmds) / sizeof(command_t);
    for (int i = 0; i < len; i++) {
        if (strcmp(cmd, print_cmds[i].cmd_name) == 0) {
            print_cmds[i].cmd_pointer();
        }
    }
}

void printProfits(){
    int ncustomers = 5;
    int sales = 12;
    int profits = ncustomers * sales;
    printf("Today's profits is: $%d\n", profits);
}

void printGreetings(){
    int date = 2;
    int month = 3;
    printf("Welcome to our Coffee Shop. Today is %d/%d/2024.\n", date, month);
}

void printBest(){
    int date = 2;
    if (date % 2 == 0) {
        printf("Today's best item on the menu is Mocha Latte.\n");
    } else {
        printf("Today's best item on the menu is Matcha Oat Milk.\n");
    }
}

void printRefunds(){
    int ncustomers = 3;
    int returns = 5;
    printf("Today, %d asks for a refund because the drink was bad.\n", ncustomers);
    printf("We lost $%d.\n", ncustomers*returns);
}

void printMusic(){
    bool a = true;
    char playlist[5][10] = {"Abel", "Ariana", "Adele", "Lofi", "Sabrina"};
    if (a) {
        printf("Today's music playlist: \n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c", playlist[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No music is playing.");
    }
}

int main() {
    execute_command("profits");
    execute_command("greetings");
    execute_command("best");
    execute_command("refunds");
    execute_command("music");

    return 0;
}