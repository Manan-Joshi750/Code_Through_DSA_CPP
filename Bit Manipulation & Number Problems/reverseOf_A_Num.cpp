#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter any number : ";
    cin >> n;
    cout << "The number " << n << " in reversed form is : ";

    int reversed_num = 0;
    while(n>0){
        int last_digit = n % 10;
        reversed_num = reversed_num*10 + last_digit;
        n = n/10;
    }
    cout << reversed_num;
    return 0;
}