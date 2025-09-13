#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** matrix;   
    int rows, cols; 

    void allocate(int r, int c, int fillValue = 0) {
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = fillValue;
            }
        }
    }

    void deallocate() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

public:
    DynamicMatrix(int r, int c, int fillValue = 0) {
        allocate(r, c, fillValue);
    }

    ~DynamicMatrix() {
        deallocate();
    }

    void resize(int newRows, int newCols, int fillValue = 0) {
        int** newMatrix = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols) {
                    newMatrix[i][j] = matrix[i][j]; 
                } else {
                    newMatrix[i][j] = fillValue;   
                }
            }
        }

        deallocate();

        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    void transpose() {
        int** newMatrix = new int*[cols];
        for (int i = 0; i < cols; i++) {
            newMatrix[i] = new int[rows];
            for (int j = 0; j < rows; j++) {
                newMatrix[i][j] = matrix[j][i];
            }
        }

        deallocate();

        int temp = rows;
        rows = cols;
        cols = temp;
        matrix = newMatrix;
    }

    int& at(int r, int c) {
        return matrix[r][c];
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = matrix[i][j];
                if ((i + j) % 2 == 1) { 
                    val += 2;
                }
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DynamicMatrix mat(2, 3, 1); 

    mat.at(0, 1) = 5;
    mat.at(1, 2) = 7;

    cout << "Original matrix:" << endl;
    mat.print();

    cout << "\nAfter resizing to 3x4 (fill = 9):" << endl;
    mat.resize(3, 4, 9);
    mat.print();

    cout << "\nAfter transpose:" << endl;
    mat.transpose();
    mat.print();

    return 0;
}
