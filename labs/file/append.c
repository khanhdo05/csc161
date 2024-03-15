#include <stdio.h>
#include <time.h>

int main(void) {
    FILE *fp;
    char s[1024];
    int linecount=0;
    fp = fopen("log.txt", "r");
    while (fgets(s, sizeof s, fp) != NULL)
    fp = fopen("log.txt", "w");
    fprintf(fp, "%s", s);
    fprintf(fp, "Program was run at time %ld\n", time(NULL));
    fclose(fp);
    return(0);
}