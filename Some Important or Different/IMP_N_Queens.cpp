#include<iostream>
using namespace std;
//N_QUEENS Problem.
bool isSafe(int** arr, int x, int y, int n){
    for(int row=0; row<x; row++){
        if(arr[row][y] == 1){
            return false; // If a queen exists in the same column, return false.
        }
    }
    // Diagonal check - top-left direction.
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col] == 1){
            return false; // If a queen exists in the top-left diagonal, return false.
          }
        row--;
        col--;
    }
    // Diagonal check - top-right direction.
    row=x;
    col=y;
    while(row>=0 && col>=0){
        if(arr[row][col] == 1){
            return false; // If a queen exists in the top-right diagonal, return false.
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(int** arr, int x, int n){
    if(x>=n){
    return true;
    }
    for(int col=0; col<n; col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col] = 1;
            if(nQueen(arr, x+1, n)){
                return true;
            }
            arr[x][col] = 0;  //BACK_TRACKING.
        }
    }

    return false;
}
//In the entire problem , 1 will be basically representing that the queen is present there. 
int main(){
    int n;
    cout << "Enter the dimensions of the n*n chess_board : ";
    cin >> n;

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }

    if(nQueen(arr, 0 ,n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
            }cout << endl;
        }
    }

    return 0;
}