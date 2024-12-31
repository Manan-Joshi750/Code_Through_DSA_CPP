#include <iostream>
using namespace std;

int main() {
    // Declare variables to store the two numbers and the result
    double num1, num2, result;
    char operation;

    // Prompt the user to enter the first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Prompt the user to enter an operator
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;

    // Prompt the user to enter the second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Perform the operation based on the user input
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            // Check if the denominator is zero
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            // Handle invalid operator input
            cout << "Error: Invalid operator." << endl;
            break;
    }

    return 0;
}