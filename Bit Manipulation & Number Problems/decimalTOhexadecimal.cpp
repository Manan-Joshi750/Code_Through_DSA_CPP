#include <iostream>
#include <string>
using namespace std;

string decimalToHexadecimal(int n) {
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";
    
    while (n > 0) {
        int remainder = n % 16;
        hex = hexDigits[remainder] + hex;
        n /= 16;
    }
    
    return (hex == "") ? "0" : hex; // Handle the case when n is 0.
}

int main() {
    int n;
    cout << "Enter the number in decimal form : ";
    cin >> n;
    cout << "The hexadecimal form of " << n << " is : " << decimalToHexadecimal(n) << endl;
    return 0;
}