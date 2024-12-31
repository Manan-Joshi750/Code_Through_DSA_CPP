#include<iostream>
using namespace std;

int main(){
    int n;
    do {
        cout << "Enter a number: ";
        cin >> n;
        if(n <= 0) {
            cout << "Please enter the number again." << endl;
        }
    } while(n <= 0);

    cout << "All digits of the entered positive number from right to left are: ";
    while(n > 0){
        int last_digit = n % 10;
        cout << last_digit << " ";
        n = n / 10;
    }
    return 0;
}