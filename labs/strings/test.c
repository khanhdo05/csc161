#include <stdio.h>
#include <string.h>

int main (void){
char computerscience[16] = "isawesome";
char isawesome[32] = "computerscience";

printf("strlen (computerscience): %lu\n", strlen (computerscience) );
printf("strlen (isawesome): %lu\n", strlen (isawesome) );

printf("computerscience: %s\n", computerscience );
printf("isawesome: %s\n", isawesome );

printf("Concatenate the strings: %s", strcat (isawesome, computerscience));



return 0;
}