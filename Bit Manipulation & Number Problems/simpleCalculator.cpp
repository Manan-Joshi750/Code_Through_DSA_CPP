#include <iostream>
using namespace std;

int main() {
    int operand1, operand2;
    char opetr; 
    cout << "Enter the values of two operands: ";
    cin >> operand1 >> operand2;
    cout << "Enter the operator that you want to apply on the two operands: ";
    cin >> opetr;

    switch(opetr) {
        case '+': 
            cout << "Addition of " << operand1 << " and " << operand2 << " gives: " << operand1 + operand2 << endl;
            break;
        case '-': 
            cout << "Subtraction of " << operand1 << " and " << operand2 << " gives: " << operand1 - operand2 << endl;
            break;
        case '*': 
            cout << "Multiplication of " << operand1 << " and " << operand2 << " gives: " << operand1 * operand2 << endl;
            break;
        case '/': 
            if (operand2 != 0) {
                cout << "Division of " << operand1 << " and " << operand2 << " gives: " << operand1 / operand2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default: 
            cout << "Operator Not Found !!" << endl;
            break;
    }
    return 0;
}