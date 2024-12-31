#include<iostream>
using namespace std;

//So nCr = n! / ((n-r)! * r!)
int calcFactorial(int n){
    int factorial = 1;
    for(int i=2; i<=n; i++){
        factorial *= i;
    }
    return factorial;
}

int main(){
    int n, r, result;
    cout << "Enter the total number of items in the set (n) : ";
    cin >> n;
    cout << "Enter the number of items to be chosen (r) : ";
    cin >> r;

    result = calcFactorial(n) / (calcFactorial(n-r) * calcFactorial(r));
    cout << "The value of " << n << "C" << r << " is : " << result;
    return 0;
}