#include <iostream>
#include <vector>

using namespace std;

double determinant(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    for (int col = 0; col < n; col++) {
        vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
        for (int i = 1; i < n; i++)
            for (int j = 0, sub_j = 0; j < n; j++)
                if (j != col) submatrix[i - 1][sub_j++] = matrix[i][j];

        det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * determinant(submatrix);
    }
    return det;
}

int main() {
    int n;
    cout << "Введите размерность матрицы: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cout << "Определитель матрицы: " << determinant(matrix) << endl;
    return 0;
}
