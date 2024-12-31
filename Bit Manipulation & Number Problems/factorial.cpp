#include<iostream>
#define MOD 1000000007
using namespace std;

int calcFactorial(int n){
    int factorial = 1;
    for(int i=2; i<=n; i++){
        factorial *= i;
    }
    return factorial;
}

//This shows how we can find the factorial of even a large number using modulus which is not possible using the above function.
long long factorialMod(long long m, long long mod) {
    long long result = 1;
    for (long long i = 2; i <= m; i++) {
        result = (result * i) % mod;
    }
    return result;
}

int main(){
    int n, fact;
    cout << "Enter the number you want to find the factorial of : ";
    cin >> n;
    fact = calcFactorial(n);
    cout << "The Factorial of " << n << " is : " << fact << endl;

    long long m = 100000;  // Example large number
    cout << "Factorial of " << m << " modulo " << MOD << " is : " << factorialMod(m, MOD) << endl;
    return 0;
}