/*
  Author: Khanh Do                  
  Class: CSC-161-01                  
 */

/***************************************/
/*           TICKET PRICING            */
/*    This program will calculate the  */
/*   purchases of tickets at a theater */
/***************************************/

#include <stdio.h>

int main(void) {

    // Initializing and assigning constant values
    const float thirty = 30.00;
    const float twenty_five = 25.00;
    const float twenty = 20.00;
    const float fifteen = 15.00;
    const float discount = 5.00;
    const int child = 5;
    const int senior = 55;

    // Initializing variables
    int num_ticket, location, time, age;
    float total_price = 0.0;

    // Number of tickets input
    printf("Welcome to The Strand!\nTicket number should be larger than 0 and a whole number.\nEnter the number of tickets you would like to purchase: ");
    scanf("%d", &num_ticket);

    /*
        Main program loop. Each loop is for each ticket round. 
        Will run loop from 1 to the number of tickets, inclusively.
    */
    for (int i = 1; i <= num_ticket; i++) {

        float ticket_price;
        printf("Enter information for ticket number %d.\n", i);

        // Age input
        printf("Please enter the age of ticket holder: ");
        scanf("%d", &age);

        // Handle Age Invalid Inputs
        if ((age < 0) || (age > 150)) {
            printf("Invalid age. Age is between 0 and 150. Please try again!\n");
            i--; // decrement i in order to rerun the loop
            continue;
        }

        // Location input
        printf("Which location would you like to buy ticket for?\nType '1' for Main floor-Middle Section\nType '2' for Main floor-sides\nType '3' for Balcony\nChoose here: ");
        scanf("%d", &location);

        // Handle Location Invalid Inputs
        if ((location != 1 && location != 2) && location != 3) {
            printf("Invalid location. Pick from 1, 2, or 3. Please try again!\n");
            i--;
            continue;
        }

        // Time input
        printf("Please select show time:\nType '1' to select Matinee\nType '2' to select Evening\nChoose here: ");
        scanf("%d", &time);    

        // Handle Time Invalid Inputs
        if ((time != 1 && time != 2) && time != 3) {
            printf("Invalid time. Pick from 1, 2, or 3. Please try again!\n");
            i--;
            continue;
        } 

        // Process Location and Time
        switch (time) {
            case 1: // Matinee
                switch (location) {
                    case 1: // Main floor - middle section
                        ticket_price = twenty_five;
                        break;
                    case 2: // Main floor - sides
                        ticket_price = twenty;
                        break;
                    case 3: // Balcony
                        ticket_price = fifteen;
                        break;
                }
                break;
            case 2: // Evening
                switch (location) {
                    case 1: // Main floor - middle section
                        ticket_price = thirty;
                        break;
                    case 2: // Main floor - sides
                        ticket_price = twenty_five;
                        break;
                    case 3: // Balcony
                        ticket_price = twenty;
                        break;
                }
        }

        // Handle special prices
        if ((age >= 0) && (age <= 5)) { // Age 0-5, price is free
            ticket_price = 0.0;
        }
        else if (((age >= 6) && (age <= 10)) || (age >= 55)) { // Age 6-10 or 55 up, price -$5
            ticket_price -= discount;
        }

        total_price += ticket_price; // Add ticket price of each round to the total price, which is outside of the ticket loop

        // Print Information
        printf("    Ticket %d Information\n", i);
        printf("Ticket holder's age:  %d years old\n", age);
        switch (time) {
            case 1:
                printf("Time selected:        Matinee\n");
                break;
            case 2:
                printf("Time selected:        Evening\n");
                break;
        }
        switch (location) {
            case 1:
                printf("Location selected:    Main floor - middle section\n");
                break;
            case 2:
                printf("Location selected:    Main floor - sides\n");
                break;
            case 3:
                printf("Location selected:    Balcony\n");
                break;

        }
        printf("Ticket Price:         $%.2f\n", ticket_price);
    }
    
    printf("     Checkout\n");
    printf("Total Price: $%.2f\n", total_price);

    return 0;
}
