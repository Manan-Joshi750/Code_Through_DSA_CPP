#include<iostream>
#include<climits>
using namespace std;

void columnWiseSum(int arr[][3], int row, int col){
    cout << "Column Wise sum is : ";
    for(int j = 0; j < col; j++){  
        int sum = 0;
        for(int i = 0; i < row; i++){
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

void rowWiseSum(int arr[][3], int row, int col){
    cout << "Row Wise sum is : ";
    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int largestRowSum(int arr[][3], int row, int col){
    int maxSum = INT_MIN;
    int rowIndex = -1;

    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum += arr[i][j];
        }

        if(maxSum < sum){
            maxSum = sum;
            rowIndex = i;
        }
    }

    cout << "Maximum Row Sum is : " << maxSum;
    return rowIndex;
}

int largestColumnSum(int arr[][3], int row, int col){
    int maxSum = INT_MIN;
    int columnIndex = -1;

    for(int j = 0; j < col; j++){  
        int sum = 0;
        for(int i = 0; i < row; i++){
            sum += arr[i][j];
        }

        if(maxSum < sum){
            maxSum = sum;
            columnIndex = j;
        }
    }

    cout << "Maximum Column Sum is : " << maxSum;
    return columnIndex;
}

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

    columnWiseSum(arr, row, 3);
    rowWiseSum(arr, row, 3);
    cout << " and it is at row index " << largestRowSum(arr, row, 3) << endl;
    cout << " and it is at column index " << largestColumnSum(arr, row, 3) << endl;
    return 0;
}