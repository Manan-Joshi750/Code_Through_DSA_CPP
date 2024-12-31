#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the height of pyramid : ";
    cin >> n;
//In the form of an right angled triangle.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
//In the form of an equilateral triangle.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        for(int j=1; j<=i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
//In the form of equilateral traingle-Part 2
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}