#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci sequence : ";
    cin >> n;
    // Initializing the first two terms of the Fibonacci sequence
    int first = 0, second = 1;
    cout << "Fibonacci sequence : " << first << " ";

    if (n > 1) {
        // Printing the second term
        cout << second << " ";
    }
    // Generating and printing the rest of the Fibonacci sequence
    for (int i = 3; i <= n; i++) {
        int next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }
    cout << endl;

    return 0;
}