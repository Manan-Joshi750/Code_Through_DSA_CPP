#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the number of rows : ";
    cin >> row;

    int arr[row][3];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < 3; j++){
            cout << "Enter the element at index " << i << j << " : ";
            cin >> arr[i][j];
        }
    }

    cout << "Wave print of the 2D array is : ";
    for(int j = 0; j < 3; j++){
        if(j & 1){ // if column index is odd
            for(int i = row-1; i>=0; i--){
                cout << arr[i][j] << " ";
            }
        } else { // if column index is even
            for(int i = 0; i<row; i++){
                cout << arr[i][j] << " ";
            }
        }
    }
}