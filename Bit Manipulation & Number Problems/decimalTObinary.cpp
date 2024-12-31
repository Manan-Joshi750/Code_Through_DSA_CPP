#include <iostream>
using namespace std;

int decimalToBinary(int n) {
    int x = 1;
    int ans = 0;
//This loop and the statement written just after it are for finding the highest power of 2 just before the entered number n.
    while (x <= n) {
        x *= 2;
    }
    x /= 2;
//And this loop generates the binary form of the entered number.
    while (x > 0) {
        int lastDigit = n / x; //This keeps the track of what will come out of 0 and 1 at different powers of 2. 
        n -= lastDigit * x; //This make sure that if we have included any power of 2, then it shouldn't be considered again.
        x /= 2; //Moves to the next lower power of 2.
        ans = ans * 10 + lastDigit; //Binary form getting generated.
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number in decimal form: ";
    cin >> n;
    cout << "The binary form of " << n << " is : " << decimalToBinary(n);
    return 0;
}