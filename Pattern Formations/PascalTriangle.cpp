#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the height of the pattern: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int coeff = 1;
        for (int space = 1; space <= n - i; space++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            if (j > 0) {
                coeff = coeff * (i - j + 1) / j;
            }
            cout << coeff << "   ";
        }
        cout << endl;
    }
    return 0;
}