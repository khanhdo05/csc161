/**
 * A program to calculate credit card payoffs with daily interest.
 * 
 * \author Khanh Do
 */

#include <stdio.h>
#include <math.h>

// Helper Functions
int calculateDaysInMonth(int month);
double calculateDPR(double APR);
double calculateInterestAccrued(double DPR, int days, double remaining_balance);
double calculateMinimumPay(double remaining_balance, double interest_accrued, double payment);
double updateBalance(double remaining_balance, double payment, double interest_accrued);
int calculateTotalMonths(double INITIAL, double APR, double monthly_minimum, int start_month, double *total_payment);
double calculateTotalPayment(double monthly_minimum);

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

// Define a function that helps calculate the DPR rate
double calculateDPR(double APR) {
    return (APR / 365);
}

// Define a function that helps calculate the interest accrued in a month
double calculateInterestAccrued(double DPR, int days, double remaining_balance) {
    return (remaining_balance * (DPR * days));
}

// Define a function that helps calculate minimum payment in a month
double calculateMinimumPay(double remaining_balance, double interest_accrued, double payment) {
    if (remaining_balance >= payment) {
        return payment;
    }
    else {
        return (remaining_balance + interest_accrued);
    }
}

// Define a function that helps update the remaining_balance each cycle
double updateBalance(double remaining_balance, double payment, double interest_accrued) {
    return (remaining_balance - payment + interest_accrued);
}

// Define a function that helps calculate how many months
int calculateTotalMonths(double INITIAL, double APR, double monthly_minimum, int start_month, double *total_payment) {
    int total_month = 0;
    double remaining_balance = INITIAL;
    double payment = 35.00;
    int month = start_month;

    // Loop until remain_balance is $0
    while (remaining_balance > 0) {

        // Calculate the days in that month
        int days = calculateDaysInMonth(month);
        
        // Calculate the daily interest rate
        double DPR = calculateDPR(APR);

        // Calculate the interest accrued for the current month
        double interest_accrued = calculateInterestAccrued(DPR, days, remaining_balance);

        // Calculate the minimum payment needed
        payment = calculateMinimumPay(remaining_balance, monthly_minimum, payment);

        // Add to total_payment
        *total_payment += payment;

        // Updating the remaining balance
        remaining_balance = updateBalance(remaining_balance, payment, interest_accrued);

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
    const double APR = 0.18; 
    double payment = 35.00;             // dollars per month
    const double INITIAL = 500.00;      // dollars
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
    total_month = calculateTotalMonths(INITIAL, APR, payment, start_month, &total_payment);

    // Printing the resulting table
    printf ("Table of credit card payoff with daily interest\n");
    printf("Cycle   Month   Interest   Payment    Balance\n");

    // For loop to print the format
    for (int i = 0; i < total_month; i++) {




        printf("%3d%3d     $  %1.2f    $  %1.2f    $  %1.2f\n", i, month, interest_accrued, monthly_minimum, remaining_balance);
    }

    // Conclusion text
    printf("After %d months, you paid $%.2f on an initial balance of $%.2f\n", total_month, total_payment, INITIAL);
    
    return 0;
}