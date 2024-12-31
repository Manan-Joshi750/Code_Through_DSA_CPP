#include <iostream>
using namespace std;

int main() {
    // Declare variables to store the original number and its reverse
    int num, reversedNum = 0, remainder, originalNum;

    // Prompt the user to enter a number
    cout << "Enter an integer: ";
    cin >> num;

    // Store the original number to compare later
    originalNum = num;

    // Reverse the number
    while (num != 0) {
        // Get the last digit of the number
        remainder = num % 10;
        // Append the digit to the reversed number
        reversedNum = reversedNum * 10 + remainder;
        // Remove the last digit from the number
        num /= 10;
    }

    // Check if the original number is equal to the reversed number
    if (originalNum == reversedNum) {
        cout << originalNum << " is a palindrome." << endl;
    } else {
        cout << originalNum << " is not a palindrome." << endl;
    }

    return 0;
}