#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;
   
    int sum = 0;
    while(n >= 0){
        sum += n;
        cout << "Enter a number again : ";
        cin >> n;
    }

    cout << "The Sum Of All Positive Numbers Entered Till Now Is : " << sum;
    return 0;
}