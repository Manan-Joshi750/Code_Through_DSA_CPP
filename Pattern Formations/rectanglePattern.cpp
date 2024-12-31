#include<iostream>
using namespace std;

int main(){
    int rows, colm;
    cout << "Enter the number of rows : ";
    cin >> rows;
    cout << "Enter the number of columns : ";
    cin >> colm;

    for(int i=1; i<=rows; i++){
        for(int j=1; j<=colm; j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}