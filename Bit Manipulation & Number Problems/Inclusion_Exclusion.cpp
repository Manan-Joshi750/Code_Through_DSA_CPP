#include <iostream>
using namespace std;
/*To find the number of numbers in the interval [1,n] that are divisible by 
a or b, you can use the principle of Inclusion-Exclusion. This principle states that the count of numbers divisible by 
a or b is given by the sum of the counts of numbers divisible by a and b, minus the count of numbers divisible by both 
a and b (to avoid double-counting those numbers). */

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the least common multiple (LCM)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int divisible(int n, int a, int b) {
    int c1 = n / a;
    int c2 = n / b;
    int c3 = n / lcm(a, b);
    return c1 + c2 - c3;
}

int main() {
    int n, a, b;
    cout << "Enter the value of n, a and b respectively : ";
    cin >> n >> a >> b;
    cout << "Number of integers in the interval [1, " << n << "] divisible by " << a << " or " << b << " is : " << divisible(n, a, b);
    return 0;
}