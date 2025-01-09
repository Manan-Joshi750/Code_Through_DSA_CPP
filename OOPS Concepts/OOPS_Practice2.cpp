/*Objective: Demonstrate single inheritance with functionality extension.
Task: Create a class BankAccount with attributes accountNumber and balance. Derive
a class SavingsAccount from BankAccount with an additional method calculateInterest
that calculates interest based on a fixed interest rate (e.g., 5%) and updates the
balance. Implement methods to deposit and withdraw money in the BankAccount class
and use them in SavingsAccount. */
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    protected:
    string accountNumber;
    double balance;

    public:
    // Constructor to initialize account number and balance
    BankAccount(const string &accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    // Method to display account details
    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    private:
    static constexpr double interestRate = 0.05; // Fixed interest rate of 5%

    public:
    // Constructor to initialize account number and balance in the base class
    SavingsAccount(const string &accNum, double initialBalance) : BankAccount(accNum, initialBalance)
    {}
    // Method to calculate and add interest to the balance
    void calculateInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Interest Added: " << interest << ". New Balance: " << balance << endl;
    }
};

int main() {
    // Create a SavingsAccount object
    SavingsAccount savings("123456789", 1000.0);
    // Display initial account details
    savings.displayAccountDetails();
    // Perform some transactions
    savings.deposit(500.0); // Deposit money
    savings.withdraw(200.0); // Withdraw money
    // Calculate and add interest
    savings.calculateInterest();
    // Display final account details
    savings.displayAccountDetails();
    return 0;
}