/**
 * A program to calculate credit card payoffs with daily interest.
 * 
 * \author Khanh Do
 */

#include <stdio.h>
#include <math.h>

int main() {

    // Initializing variables
    float APR = 0.18; 
    int DPR;
    double PAYMENT = 35.00; // dollars per month
    const double INITIAL = 500.00; // dollars
    int days, total_month, start_month, month, cycle_end;
    float interest;
    float balance = INITIAL;
    float total_payment = 0.00;

    // Welcome text
    printf("Current APR = %d%%, monthly payment = $%.2f, initial payment = $%.2f\n", (int)(APR*100), PAYMENT, INITIAL);

    // Ask for user's input of starting month
    printf("Which month are you starting at (1-12): ");
    scanf("%d", &start_month);
    printf("For how many months: ");
    scanf("%d", &total_month);
    cycle_end = total_month - 1;

    // Printing the resulting table
    printf ("Table of credit card payoff with daily interest\n");
    printf("Cycle   Month   Interest   Payment   Balance\n");

    // For loop to print the format

    // Conclusion text
    printf("After %d months, you paid $%.2f on an initial balance of $%.2f\n", total_month, total_payment, INITIAL);
    
    return 0;
}