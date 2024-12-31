#include<iostream>
using namespace std;

int binaryTodecimal(int n) {
    int ans = 0;
    int x=1;
    
    while (n>0) {
        int y = n%10;
        ans += x*y;
        x *= 2;
        n/=10;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number in binary form : ";
    cin >> n;
    cout << "Decimal form of " << n << " is : " << binaryTodecimal(n) << endl;
    return 0;
}