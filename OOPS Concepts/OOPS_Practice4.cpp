/*Objective: Use single inheritance with a balance update.
Task: Create a base class Account with an attribute balance and methods to deposit
and withdraw. Derive a class CheckingAccount that charges a fee for each transaction.
Implement methods in CheckingAccount to withdraw with an additional transaction fee
(e.g., $1). Display the balance after each transaction. */
#include <iostream>
using namespace std;

class Account {
    protected:
    double balance;

    public:
    // Constructor to initialize balance
    Account(double initialBalance) : balance(initialBalance) {}

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }

        displayBalance();
    }

    // Method to withdraw money
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid withdrawal amount!" << endl;
        }

        displayBalance();
    }

    // Method to display balance
    void displayBalance() const {
        cout << "Current Balance: $" << balance << endl;
    }
};

class CheckingAccount : public Account {
    private:
    const double transactionFee = 1.0; // Fee for each transaction

    public:
    // Constructor to initialize balance in CheckingAccount
    CheckingAccount(double initialBalance) : Account(initialBalance) {}

    // Overriding withdraw method to include transaction fee
    void withdraw(double amount) override {
        double totalAmount = amount + transactionFee;
        if (amount > 0 && totalAmount <= balance) {
            balance -= totalAmount;
            cout << "Withdrew: $" << amount << " with a transaction fee of $" << transactionFee << endl;
        } else {
            cout << "Insufficient balance or invalid withdrawal amount!" << endl;
        }
        
        displayBalance();
    }
};

int main() {
    // Create a CheckingAccount object with an initial balance
    CheckingAccount myAccount(100.0);
    // Perform some transactions
    myAccount.deposit(50); // Deposit $50
    myAccount.withdraw(30); // Withdraw $30 (fee applied)
    myAccount.withdraw(150); // Attempt to withdraw $150 (insufficient balance)
    myAccount.withdraw(20); // Withdraw $20 (fee applied)
    return 0;
}