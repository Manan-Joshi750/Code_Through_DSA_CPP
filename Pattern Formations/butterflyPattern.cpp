#include<iostream>
using namespace std;
//Butterfy pattern printing. 
int main() {
    int n;
    cout << "Enter the number of lines up to which you want to observe the pattern: ";
    cin >> n;
    // Upper part of the butterfly pattern
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        int space = 2 * (n - i);
        for (int j = 1; j <= space; j++) {
            cout << "  "; // Double space for wider gap
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    // Lower part of the butterfly pattern
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        int space = 2 * (n - i);
        for (int j = 1; j <= space; j++) {
            cout << "  "; // Double space for wider gap
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}