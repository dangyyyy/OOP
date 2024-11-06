#include <iostream>

using namespace std;

double determinant(double** matrix, int n) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    for (int col = 0; col < n; col++) {
        double** submatrix = new double*[n - 1];
        for (int i = 0; i < n - 1; i++)
            submatrix[i] = new double[n - 1];

        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int j = 0; j < n; j++) {
                if (j != col) {
                    submatrix[i - 1][sub_j] = matrix[i][j];
                    sub_j++;
                }
            }
        }

        det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * determinant(submatrix, n - 1);

        for (int i = 0; i < n - 1; i++)
            delete[] submatrix[i];
        delete[] submatrix;
    }
    return det;
}

int main() {
    int n;
    cout << "Введите размерность матрицы: ";
    cin >> n;

    double** matrix = new double*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new double[n];

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cout << "Определитель матрицы: " << determinant(matrix, n) << endl;

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
