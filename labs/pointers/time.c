#include <stdio.h>

/**
 * Take in a total number of seconds and split it up into parts
 * 
 * \param total_seconds The input number of seconds
 * \param days    Output: the number of whole days in total_seconds
 * \param hours   Output: the number of whole hours in total_seconds
 * \param minutes Output: the number of whole minutes in total_seconds
 * \param seconds Output: the remaining seconds
 */
void split_time(unsigned long total_seconds, unsigned int* days, 
             unsigned int* hours, unsigned int* minutes,
             unsigned int* seconds);

void split_time(unsigned long total_seconds, unsigned int* days, unsigned int* hours, unsigned int* minutes, unsigned int* seconds) {
    int minutess = total_seconds / 60;
    *seconds = total_seconds % 60;
    int hourss = minutess / 60;
    *minutes = minutess % 60;
    *days = hourss / 24;
    *hours = hourss % 24;
}

int main(void) {
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;
    unsigned int days;
    split_time(10000000, &days, &hours, &minutes, &seconds);
    printf("Days: %d Hours: %d Minutes: %d Seconds: %d\n", days, hours, minutes, seconds);
}

