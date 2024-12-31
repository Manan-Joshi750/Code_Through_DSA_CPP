#include<iostream>
#include<cmath>
using namespace std;
//Check whether the entered number is a prime or not.
int main() {
    int n;
    cout << "Enter any number: ";
    cin >> n;

    if (n <= 1) {
        cout << "Non Prime" << endl;
        return 0;
    }

    bool isPrime = true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        cout << "Prime" << endl;
    } else {
        cout << "Non Prime" << endl;
    }

    return 0;
}