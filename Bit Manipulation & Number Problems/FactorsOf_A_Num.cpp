#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    if(n == 0) {
        cout << "0 has an infinite number of factors." << endl;
    } else if(n == 1) {
        cout << "1 is the only factor of 1." << endl;
    } else {
        cout << "Factors of " << n << " are : ";
        for(int i = 1; i <= n; ++i) {
            if(n % i == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}