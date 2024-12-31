#include<iostream>
using namespace std;

int calcPower(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return base;
    }

    int ans = calcPower(base, exponent/2);
    if(exponent % 2 == 0){
        return ans * ans;
    } else {
        return base * ans * ans;
    }
}

int main(){
    int base;
    cout << "Enter the value of base : ";
    cin >> base;

    int exponent;
    cout << "Enter the value of exponent : ";
    cin >> exponent;

    cout << base << " to the power " << exponent << " equals " << calcPower(base, exponent);
    return 0;
}