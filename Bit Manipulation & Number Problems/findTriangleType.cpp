#include<iostream>
using namespace std;

int main(){
    int sideA, sideB, sideC;
    cout << "Enter the three sides of a triangle : ";
    cin >> sideA >> sideB >> sideC;

    if(sideA == sideB && sideB == sideC){
        cout << "It's an Equilateral Triangle";
    }
    else if(sideA == sideB || sideB == sideC || sideC == sideA){
        cout << "It's an Isosceles Triangle";
    }
    else {
        cout << "It's an Scalene Triangle";
    }
    return 0;
}