/*
  Author: Khanh Do                  
  Class: CSC-161-01                  
 */

/***************************************/
/*            TICKET PRICING           */
/*    This program will calculate the  */
/*   purchases of tickets at a theater */
/***************************************/

#include <stdio.h>

int main(void) {

    /* 
        Valid ages for ticket holders are between 0 and 150 (inclusive). 
        Tickets for children 5 and under are free regardless of time and location. 
        Children between 6 and 10, inclusive, and senior citizens (age 55 and older) receive a $5.00 discount.
    */

    int num_ticket;
    int location;
    int seat;

    // Number of tickets input
    printf("Enter the number of tickets you would you like to purchase: ");
    scanf("%d", &num_ticket);

    // Location input
    printf("Which location would you like to buy ticket for?\nType '1' for Main floor-Middle Section\nType '2' for Main floor-sides\nType '3' for Balcony\nChoose here: ");
    scanf("%d", &location);

    // Seat input
    printf("Please select seat:\nType '1' to select Matinee\nType '2' to select Evening\nChoose here: ");
    scanf("%d", &seat);

    switch (location) {
        case 1:
            
    }

    return 0;
}
