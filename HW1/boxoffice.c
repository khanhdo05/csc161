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

    const float thirty = 30.00;
    const float twenty_five = 25.00;
    const float twenty = 20.00;
    const float fifteen = 15.00;
    const float discount = 5.00;
    const int child = 5;
    const int senior = 55;

    int num_ticket, location, time, age;
    float total_price = 0.0;

    // Number of tickets input
    printf("Welcome to The Strand!\nEnter the number of tickets you would like to purchase: ");
    scanf("%d", num_ticket);

    for (int i = 1; i <= num_ticket; i++) {
        // Location input
        printf("Which location would you like to buy ticket for?\nType '1' for Main floor-Middle Section\nType '2' for Main floor-sides\nType '3' for Balcony\nChoose here: ");
        scanf("%d", &location);

        // Seat input
        printf("Please select show time:\nType '1' to select Matinee\nType '2' to select Evening\nChoose here: ");
        scanf("%d", &time);

        // Age input
        printf("Please enter the age of ticket holder: ");
        scanf("%d", &age);

        
    }

    printf("Total Price: %.2f dollars.", total_price);

    return 0;
}
