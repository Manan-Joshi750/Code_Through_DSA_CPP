/*Write a program simulating an ATM where the Customer class contains information
about the customer’s account balance. Another class ATM has a function that accepts a
Customer object and performs operations like withdrawal and balance checking. The
ATM class should not allow a withdrawal if the customer has insufficient funds. Handle
the case where the customer tries to withdraw more than available balance and ensure
that the withdrawal process updates the balance correctly. */
#include <iostream>
using namespace std;

class Customer {
    private:
    double balance;

    public:
    Customer(double b) : balance(b) {}
        double getBalance() const {
        return balance;
    }

    void updateBalance(double amount) {
        balance += amount;
    }
};

class ATM {
    public:
    void withdraw(Customer& customer, double amount) {
        if (amount > customer.getBalance()) {
            cout << "Insufficient funds" << endl;
        } else {
            customer.updateBalance(-amount);
            cout << "Withdrawal successful. Remaining balance: " << customer.getBalance() << endl;
        }
    }

    void checkBalance(const Customer& customer) {
        cout << "Current balance: " << customer.getBalance() << endl;
    }
};

int main() {
    Customer customer1(500.00);
    ATM atm;
    atm.checkBalance(customer1);
    atm.withdraw(customer1, 200);
    atm.checkBalance(customer1);
    atm.withdraw(customer1, 400);
    return 0;
}