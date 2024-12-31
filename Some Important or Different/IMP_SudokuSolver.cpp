#include <iostream>
using namespace std;
//SUDOKU SOLVER.
const int N = 9;
// Function to check if it's safe to place a number in a given row, column, or box
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }   
    for (int y = 0; y < N; y++) {
        if (grid[y][col] == num) {
            return false;
        }
    }   
    // Check box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }  
    return true;
}
// Function to solve Sudoku using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = true;   
    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }   
    // If no empty cell is found, the Sudoku puzzle is solved
    if (isEmpty) {
        return true;
    }  
    // Placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;            
            if (solveSudoku(grid)) {
                return true;
            }            
            grid[row][col] = 0; // Backtrack if placing the number doesn't lead to a solution
        }
    }   
    return false;
}
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku solved:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists";
    }   
    return 0;
}
