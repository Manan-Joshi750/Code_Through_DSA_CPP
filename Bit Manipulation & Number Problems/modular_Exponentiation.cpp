#include<iostream>
using namespace std;
//We need to find the value of (x ^ n) % m, that is x to the power n modulo m.
//Now doing it the simple way will be of time complexity O(n), so we will be using fast exponentiation which will gice T.C of O(logn).

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)  // If exp is odd, multiply base with result
            result = (result * base) % mod;
        exp = exp >> 1;     // Divide exp by 2
        base = (base * base) % mod;  // Square the base
    }
    return result;
}

int main(){
    int x,n,m;
    cout << "Enter the value of x, n and m respectively : ";
    cin >> x >> n >> m;

    cout << x << "^" << n << " % " << m << " = " << modExp(x, n, m) << endl;
    return 0;
}