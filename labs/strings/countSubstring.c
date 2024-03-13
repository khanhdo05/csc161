#include <stdio.h>
#include <string.h>

int main(int mes_len, char *message[], char *word[]) {
    int count = 0;
    for (int i = 0; i < mes_len; i++) {
        if (strstr(*message++, *word)) {
            count += 1;
        }
    }
    printf("the substring '%s' appears %d times.", *word, count);
    return count;
}