#include<iostream>
using namespace std;
//Input would be something like 412 and we should give output as four one two. 

void sayDigits(string str[], int n){
    if(n == 0){
        return;
    }

    int digit = n % 10;
    n = n / 10;

    sayDigits(str, n);
    cout << str[digit] << " ";
}

int main(){
    int n;
    cout << "Enter any number : ";
    cin >> n;

    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << "Say Digit form of " << n << " is : ";
    sayDigits(str,n);
    return 0;
}