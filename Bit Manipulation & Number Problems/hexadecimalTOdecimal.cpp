#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    int base = 1; // 16^0

    // Start from the end of the hexadecimal string.
    for (int i = hex.length() - 1; i >= 0; --i) {
        char hexDigit = hex[i];

        if (hexDigit >= '0' && hexDigit <= '9') {
            decimal += (hexDigit - '0') * base;
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            decimal += (hexDigit - 'A' + 10) * base;
        } else if (hexDigit >= 'a' && hexDigit <= 'f') {
            decimal += (hexDigit - 'a' + 10) * base;
        }

        base *= 16; // Move to the next power of 16.
    }

    return decimal;
}

int main() {
    string hex;
    cout << "Enter the number in hexadecimal form : ";
    cin >> hex;
    cout << "The decimal form of " << hex << " is : " << hexadecimalToDecimal(hex);
    return 0;
}