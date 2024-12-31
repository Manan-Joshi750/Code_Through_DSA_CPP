#include<iostream>
using namespace std;
// Hollow Rectangle
int main() {
    int rows, colm;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> colm;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= colm; j++) {
            if (i == 1 || i == rows || j == 1 || j == colm) {
                cout << "* ";
            } else {
                cout << "  "; // Two spaces to align with "* ".
            }
        }
        cout << endl;
    }
    return 0;
}