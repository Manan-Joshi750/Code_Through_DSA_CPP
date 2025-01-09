/*Objective: Access private members of the base class through getters and setters.
Task: Create a base class BankAccount with a private attribute balance. Add public
methods deposit() and getBalance() to modify and access balance. Derive a class
SavingsAccount that has an additional interestRate attribute and a method
applyInterest() to add interest to the balance. */
#include <iostream>
using namespace std;

class BankAccount {
    private:
    double balance; // Private balance attribute

    public:
    // Constructor to initialize balance
    BankAccount(double initialBalance) {
        balance = (initialBalance >= 0) ? initialBalance : 0; // Ensure balance is non-negative
    }

    // Method to deposit an amount into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }

        displayBalance();
    }

    // Getter method to access balance
    double getBalance() const {
        return balance;
    }

    // Protected method to update balance (can be accessed by derived classes)
    protected:
    void setBalance(double newBalance) {
        if (newBalance >= 0) {
            balance = newBalance;
        } else {
            cout << "Balance cannot be negative!" << endl;
        }
    }

    // Method to display the current balance
    void displayBalance() const {
        cout << "Current Balance: $" << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    private:
    double interestRate; // Interest rate attribute

    public:
    // Constructor to initialize balance and interest rate
    SavingsAccount(double initialBalance, double rate) : BankAccount(initialBalance), interestRate(rate) {}
    
    // Method to apply interest to balance
    void applyInterest() {
        double interest = getBalance() * interestRate / 100;
        setBalance(getBalance() + interest);
        cout << "Interest applied: $" << interest << " at rate of " << interestRate << "%" << endl;
        displayBalance();
    }
};

int main() {
    // Create a SavingsAccount object with initial balance and interest rate
    SavingsAccount myAccount(1000.0, 5.0);
    // Perform some operations
    myAccount.deposit(500); // Deposit $500
    myAccount.applyInterest(); // Apply interest
    return 0;
}