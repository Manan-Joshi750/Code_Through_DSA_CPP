#include<iostream>
using namespace std;

int octalTodecimal(int n) {
    int ans = 0;
    int x=1;
    
    while (n>0) {
        int y = n%10;
        ans += x*y;
        x *= 8;
        n/=10;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number in octal form : ";
    cin >> n;
    cout << "Decimal form of " << n << " is : " << octalTodecimal(n);
    return 0;
}