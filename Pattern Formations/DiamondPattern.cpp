#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the height of the pattern: ";
    cin >> n;
    // Upper half of the diamond
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) { 
            cout << "  ";
        }
        for(int j = 1; j <= (2 * i - 1); j++) {
            cout << "* ";
        }
        cout << endl;
    }
    // Bottom half of the diamond
    for(int i = n - 1; i >= 1; i--) {  // Adjust the range to avoid repeating the middle line
        for(int j = 1; j <= n - i; j++) { 
            cout << "  ";
        }
        for(int j = 1; j <= (2 * i - 1); j++) {
            cout << "* ";
        }
        cout << endl;
    }
}