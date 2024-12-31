#include <iostream>
using namespace std;

void spiralOrder(int matrix[4][4], int m, int n) {
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Print the top row
        for (int i = left; i <= right; i++)
            cout << matrix[top][i] << " ";
        top++;
        // Print the right column
        for (int i = top; i <= bottom; i++)
            cout << matrix[i][right] << " ";
        right--;
        // Print the bottom row, if it exists
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                cout << matrix[bottom][i] << " ";
            bottom--;
        }
        // Print the left column, if it exists
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << matrix[i][left] << " ";
            left++;
        }
    }
}

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int m = 4, n = 4;

    cout << "Spiral Order : ";
    spiralOrder(matrix, m, n);
    cout << endl;
    return 0;
}