#include<iostream>
using namespace std;
//What we should know is : gcd(a,b) = gcd(a-b,b) = gcd(a%b, b).
//Also lcm(a,b) * gcd(a,b) = a*b. 
int gcdMethod1_Iteratively(int a, int b) {
    while (b!=0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
 return a;
}

int gcdMethod2_Iteratively(int a, int b) {
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }

    while(a != b){
        if(a > b){
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int gcdMethod1_Recursively(int a, int b) {
    if (b == 0)
        return a;
    return gcdMethod1_Recursively(b, a % b);
}

int gcdMethod2_Recursively(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }

    if (a > b) {
        return gcdMethod2_Recursively(a - b, b);
    } else {
        return gcdMethod2_Recursively(a, b - a);
    }
}

int main() {
    int a,b;
    cout << "Enter the two numbers : ";
    cin >> a >> b;
    cout << "The Greatest Common Divisor of " << a << " and " << b << " is : " << gcdMethod1_Iteratively(a,b) << endl;
    cout << "The Greatest Common Divisor of " << a << " and " << b << " is : " << gcdMethod2_Iteratively(a,b) << endl;
    cout << "The Greatest Common Divisor of " << a << " and " << b << " is : " << gcdMethod1_Recursively(a,b) << endl;
    cout << "The Greatest Common Divisor of " << a << " and " << b << " is : " << gcdMethod2_Recursively(a,b) << endl;
    return 0;
}