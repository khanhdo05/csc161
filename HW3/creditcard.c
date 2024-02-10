/**
 * A program to calculate credit card payoffs with daily interest.
 * 
 * \author Khanh Do
 */

#include <stdio.h>
#include <math.h>

// Helper Functions
int calculateDaysInMonth(int month);
double calculateDPR(float APT);
double calculateInterestAccrued(double DPR, int days, double balance);
double calculateMinimumPay(double remaining_balance, double monthly_minimum);
double updateBalance(double remaining_balance, double payment, double interest_accrued);
int calculateTotalMonths(int total_month, double initial_balance, double APR, double monthly_minimum);

// Define a function that helps calculate how many days is in a month
int calculateDaysInMonth(int month) {
    if (month == 2) {
        return 28;
    }
    else if ((((month == 8) || (month == 10)) || (month == 12)) || (month % 2 != 0)) {
        return 31;
    }
    else {
        return 30;
    }
}

// Main Function
int main() {

    // Initializing variables
    const double APR = 0.18; 
    double payment = 35.00;             // dollars per month
    const double INITIAL = 500.00;      // dollars
    double DPR;
    int days, total_month = 0, start_month, month, cycle_end;
    double interest_accrued;            // Represents the interest accrued for each month.
    double remaining_balance = INITIAL; // Represents the remaining balance after each month's payment.
    double monthly_minimum;             // Represents the minimum payment amount required each month.
    double total_payment = 0.00;        // Represents the total amount paid over the entire period.

    // Welcome text
    printf("Current APR = %d%%, monthly payment = $%.2f, initial payment = $%.2f\n", (int)(APR*100), payment, INITIAL);

    // Ask for user's input of starting month
    printf("Which month are you starting at (1-12): ");
    scanf("%d", &start_month);

    // Printing the resulting table
    printf ("Table of credit card payoff with daily interest\n");
    printf("Cycle   Month   Interest   Payment   Balance\n");

    // For loop to print the format

    // Conclusion text
    printf("After %d months, you paid $%.2f on an initial balance of $%.2f\n", total_month, total_payment, INITIAL);
    
    return 0;
}