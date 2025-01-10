/*Design a`Matrix`class to represent a 2D matrix. Overload the constructor to initialize
matrices of different sizes dynamically. One constructor should take the number of rows
and columns, another should take only one size for square matrices, and a default
constructor should initialize a 2x2 matrix. Also, implement a function that displays the
matrix and initialize several matrices dynamically. */
#include <iostream>
using namespace std;

class Matrix {
    private:
    int** mat;
    int rows;
    int cols;

    public:
    Matrix() {
        rows = 2;
        cols = 2;
        allocateMatrix();
        initializeMatrix(0);
    }

    Matrix(int r, int c) {
        rows = r;
        cols = c;
        allocateMatrix();
        initializeMatrix(0);
    }

    Matrix(int size) {
        rows = size;
        cols = size;
        allocateMatrix();
        initializeMatrix(0);
    }

    ~Matrix() {
        deallocateMatrix();
    }

    void allocateMatrix() {
        mat = new int*[rows];
        for (int i = 0; i < rows; ++i) {
        mat[i] = new int[cols];
        }
    }

    void deallocateMatrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void initializeMatrix(int value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = value;
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void setValue(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            mat[r][c] = value;
        } else {
            cout << "Invalid indices!" << endl;
        }
    }
};

int main() {
    cout << "Matrix 1 (Default 2x2 Matrix):" << endl;
    Matrix matrix1;
    matrix1.setValue(0, 0, 1);
    matrix1.setValue(0, 1, 2);
    matrix1.setValue(1, 0, 3);
    matrix1.setValue(1, 1, 4);
    matrix1.display();
    cout << "\nMatrix 2 (3x4 Matrix):" << endl;
    Matrix matrix2(3, 4);
    matrix2.setValue(0, 0, 1);
    matrix2.setValue(0, 1, 2);

    matrix2.setValue(0, 2, 3);
    matrix2.setValue(0, 3, 4);
    matrix2.setValue(1, 0, 5);
    matrix2.setValue(1, 1, 6);
    matrix2.setValue(1, 2, 7);
    matrix2.setValue(1, 3, 8);
    matrix2.setValue(2, 0, 9);
    matrix2.setValue(2, 1, 10);
    matrix2.setValue(2, 2, 11);
    matrix2.setValue(2, 3, 12);
    matrix2.display();
    cout << "\nMatrix 3 (4x4 Square Matrix):" << endl;
    Matrix matrix3(4);
    matrix3.setValue(0, 0, 1);
    matrix3.setValue(0, 1, 2);
    matrix3.setValue(0, 2, 3);
    matrix3.setValue(0, 3, 4);
    matrix3.setValue(1, 0, 5);
    matrix3.setValue(1, 1, 6);
    matrix3.setValue(1, 2, 7);
    matrix3.setValue(1, 3, 8);
    matrix3.setValue(2, 0, 9);
    matrix3.setValue(2, 1, 10);
    matrix3.setValue(2, 2, 11);
    matrix3.setValue(2, 3, 12);
    matrix3.setValue(3, 0, 13);
    matrix3.setValue(3, 1, 14);
    matrix3.setValue(3, 2, 15);
    matrix3.setValue(3, 3, 16);
    matrix3.display();
    return 0;
}