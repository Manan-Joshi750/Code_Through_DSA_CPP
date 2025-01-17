#include<iostream>
using namespace std;

int main(){
    int n = 3;
    int matrix[n][n] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int temp = matrix[i][j];
            matrix[i][j]  = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    cout << "Transpose of the matrix is : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}