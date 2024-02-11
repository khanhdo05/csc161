/**
 * A program to calculate credit card payoffs with daily interest.
 * 
 * \author Khanh Do
 */

#include <stdio.h>
#include <math.h>

#define APR 0.18 
#define payment 35.00    // dollars per month
#define INITIAL 500.00 // dollars

// Helper Functions
int calculateDaysInMonth(int month);
double calculateDPR();
double calculateInterestAccrued(double DPR, int days, double remaining_balance);
double calculateMinimumPay(double remaining_balance, double interest_accrued);
double updateBalance(double remaining_balance, double interest_accrued);
int calculateTotalMonths(int start_month);
double calculateTotalPayment(double monthly_minimum);

// Define a function that helps calculate how many days is in a month
int calculateDaysInMonth(int month) {
    if (month == 2) {
        return 28;
    }
    else if (((((month == 8) || (month == 10)) || (month == 12)) || (month % 2 != 0)) && ((month != 9) && (month != 11))) {
        return 31;
    }
    else {
        return 30;
    }
}

// Define a function that helps calculate the DPR rate
double calculateDPR() {
    return (APR / 365);
}

// Define a function that helps calculate the interest accrued in a month
double calculateInterestAccrued(double DPR, int days, double remaining_balance) {
    return (remaining_balance * (DPR * days));
}

// Define a function that helps calculate minimum payment in a month
double calculateMinimumPay(double remaining_balance, double interest_accrued) {
    if (remaining_balance > payment) {
        return payment;
    }
    else {
        return (remaining_balance + interest_accrued);
    }
}

// Define a function that helps update the remaining_balance each cycle
double updateBalance(double remaining_balance, double interest_accrued) {
    return (remaining_balance - payment + interest_accrued);
}

// Define a function that helps calculate how many months
int calculateTotalMonths(int start_month) {
    int total_month = 0;
    double remaining_balance = INITIAL;
    int month = start_month;

    // Loop until remain_balance is $0
    while (remaining_balance > 0.00) {

        // Calculate the days in that month
        int days = calculateDaysInMonth(month);
        
        // Calculate the daily interest rate
        double DPR = calculateDPR();

        // Calculate the interest accrued for the current month
        double interest_accrued = calculateInterestAccrued(DPR, days, remaining_balance);

        // Calculate the minimum payment needed
        double monthly_minimum = calculateMinimumPay(remaining_balance, interest_accrued);

        // Updating the remaining balance
        remaining_balance = updateBalance(remaining_balance, interest_accrued);

        // Increment total number of months by 1
        total_month += 1;

        month++;  // Increment to get the next month
        if (month > 12) {
            month = 1;  // Reset month to 1 if it exceeds 12
        }
    }

    return total_month;
}

// Main Function
int main() {

    // Initializing variables
    double DPR;
    int days, total_month = 0, start_month, month;
    double interest_accrued;            // Represents the interest accrued for each month.
    double remaining_balance = INITIAL; // Represents the remaining balance after each month's payment.
    double monthly_minimum;             // Represents the minimum payment amount required each month.
    double total_payment = 0.00;        // Represents the total amount paid over the entire period.

    // Welcome text
    printf("Current APR = %d%%, monthly payment = $%.2f, initial payment = $%.2f\n", (int)(APR*100), payment, INITIAL);

    // Ask for user's input of starting month
    printf("Which month are you starting at (1-12): ");
    scanf("%d", &start_month);

    // Calculate total months
    total_month = calculateTotalMonths(start_month);

    // Calculate the daily interest rate for the current month
    DPR = calculateDPR();

    // Printing the resulting table
    printf ("Table of credit card payoff with daily interest\n");
    printf("Cycle   Month     Interest     Payment     Balance\n");

    // For loop to print the format
    for (int i = 0; i < total_month; i++) {
        // Calculate the days in the current month
        days = calculateDaysInMonth(start_month);

        // Calculate the interest accrued for the current month
        interest_accrued = calculateInterestAccrued(DPR, days, remaining_balance);

        // Calculate the minimum payment needed for the current month
        monthly_minimum = calculateMinimumPay(remaining_balance, interest_accrued);
        total_payment += monthly_minimum;

        // Update the remaining balance for the next iteration
        remaining_balance = updateBalance(remaining_balance, interest_accrued);
        if (remaining_balance < 0.01) {
            remaining_balance = 0.00;
        }

        // Print the table row
        printf("%5d%8d     $%7.2f    $%7.2f    $%7.2f\n", i, start_month, interest_accrued, monthly_minimum, remaining_balance);

        // Increment the month for the next iteration
        start_month++;
        if (start_month > 12) {
            start_month = 1;
        }
    }

    // Conclusion text
    printf("After %d months, you paid $%.2f on an initial balance of $%.2f\n", total_month, total_payment, INITIAL);
    
    return 0;
}