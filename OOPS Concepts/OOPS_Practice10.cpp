/*Write a program to demonstrate the use of default arguments. Create a function
`calculatePrice()` that calculates the total price of an item, including tax and shipping.
Tax should default to 5% and shipping to $10 if no values are passed. Create multiple
function calls to demonstrate how default arguments work. */
#include <iostream>
using namespace std;

double calculatePrice(double basePrice, double taxRate = 0.05, double shippingCost = 10.0) {
    double taxAmount = basePrice * taxRate;
    double totalPrice = basePrice + taxAmount + shippingCost;
    return totalPrice;
}

int main() {
    double price1 = calculatePrice(100.0);
    cout << "Total price (with default tax and shipping): $" << price1 << endl;
    double price2 = calculatePrice(100.0, 0.07);
    cout << "Total price (with custom tax, default shipping): $" << price2 << endl;
    double price3 = calculatePrice(100.0, 0.08, 15.0);
    cout << "Total price (with custom tax and shipping): $" << price3 << endl;
    double price4 = calculatePrice(100.0, 0.0, 0.0);
    cout << "Total price (with no tax and no shipping): $" << price4 << endl;
    return 0;
}