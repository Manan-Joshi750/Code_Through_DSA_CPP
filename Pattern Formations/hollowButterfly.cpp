#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the height of the pattern : ";
    cin >> n;
    // Upper part of the butterfly pattern
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if(j==1 || j==i){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        int space = 2 * (n - i);
        for (int j = 1; j <= space; j++) {
            cout << "  "; // Double space for wider gap
        }
        for (int j = 1; j <= i; j++) {
            if(j==1 || j==i){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    // Lower part of the butterfly pattern
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if(j==1 || j==i){
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        int space = 2 * (n - i);
        for (int j = 1; j <= space; j++) {
            cout << "  "; // Double space for wider gap
        }
        for (int j = 1; j <= i; j++) {
            if(j==1 || j==i){
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}