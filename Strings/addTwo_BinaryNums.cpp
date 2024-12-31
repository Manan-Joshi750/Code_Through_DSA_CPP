#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int s = 0; // Initialize digit sum

    // Traverse both strings starting from the end
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1) {
        // Compute sum of last digits and carry
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);

        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;
        // Compute carry
        s /= 2;
        // Move to next digits
        i--; j--;
    }

    return result;
}

int main() {
    string a, b;
    cout << "Enter the first binary number: ";
    cin >> a;
    cout << "Enter the second binary number: ";
    cin >> b;

    cout << "The sum of the two binary numbers is: " << addBinary(a, b) << endl;
    return 0;
}