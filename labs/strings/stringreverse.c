#include <stdio.h>
#include <string.h>

/*
 * Reverse a string
 */

void string_reverse (char str[]);

void string_reverse (char str[]) {
    int len = strlen(str);
    char str_copy[len];
    strcpy(str_copy, str);

    for (int i = 0; i < strlen(str); i++) {
        str[i] = str_copy[len-1];
        len--;
    }
}

int main(void) {
    char str[6] = {'a', 'b', 'c', 't', 'o', '\0'};
    string_reverse(str);
    printf("%s\n", str);
    return 0;
}
