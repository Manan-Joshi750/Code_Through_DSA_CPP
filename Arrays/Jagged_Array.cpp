#include <iostream>
using namespace std;

int main() {
    int rows = 3; 
    int** jaggedArray = new int*[rows];

    // Allocate and initialize rows
    jaggedArray[0] = new int[2]{1, 2}; // First row with 2 columns
    jaggedArray[1] = new int[4]{3, 4, 5, 6}; // Second row with 4 columns
    jaggedArray[2] = new int[3]{7, 8, 9}; // Third row with 3 columns

    // Print the jagged array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < sizeof(jaggedArray[i]) / sizeof(jaggedArray[i][0]); ++j) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}