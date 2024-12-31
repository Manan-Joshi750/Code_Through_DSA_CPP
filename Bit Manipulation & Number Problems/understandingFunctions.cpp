#include <iostream>
using namespace std;
//Function to check whether the entered number is a power of 2 or not. 
bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}
// Function to count the number of ones in the binary representation of the entered number.
int countOnesInBinary(int num) {
    int count = 0;
    while (num > 0) {
        // Check the rightmost bit
        if (num % 2 == 1) {
            count++;
        }
        // Right shift the number to check the next bit
        num /= 2;
    }
    return count;
}

int main() {
    int number;
    cout << "Enter the number : ";
    cin >> number;

    if (isPowerOfTwo(number)) {
    cout << "Yes!! " << number << " is a power of 2." << endl;
    } else {
    cout << "Oops!! " << number << " is not a power of 2." << endl;
    }

    int onesCount = countOnesInBinary(number);
    cout << "And the number of ones in binary representation of " << number << " are : " << onesCount << endl;
    return 0;
}
