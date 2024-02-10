/**
 * A program to calculate credit card payoffs with daily interest.
 * 
 * \author Khanh Do
 */

#include <stdio.h>
#include <math.h>

int main() {

    // Assigning constant values
    const int APR = 18; // percents
    const double PAYMENT = 35.00; // dollars per month
    const double INITIAL = 500.00; // dollars

    // Initializing variables
    int days, total_month, start_month, cycle_end;
    float interest;
    float balance = INITIAL;
    float total_payment;

    // Welcome text
    printf("Current APR = %d%, monthly payment = $%f, initial payment = $%f\n", APR, PAYMENT, INITIAL);

    // Ask for user's input of starting month
    printf("Which month are you starting at: ");
    scanf("%d", start_month);
    printf("For how many months: ");
    scanf("%d", total_month);
    cycle_end = total_month - 1;

    // For loop to print the format

    // Conclusion text
    printf("After %d months, you paid $%f on an initial balance of $%f", total_month, total_payment, INITIAL);
    
    return 0;
}