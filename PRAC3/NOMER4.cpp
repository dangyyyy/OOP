#include <iostream>
using namespace std;

int main() {
    int strok, stolb;

    cout << "Введите количество строк (не более 10): ";
    cin >> strok;
    cout << "Введите количество столбцов (не более 10): ";
    cin >> stolb;

    int matrix[10][10];
    int arr[100];  
    int size = strok * stolb;

    cout << "Введите элементы матрицы: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int top = 0, bottom = strok - 1, left = 0, right = stolb - 1;
    int index = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = arr[index++];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = arr[index++];
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = arr[index++];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = arr[index++];
            }
            left++;
        }
    }

    cout << "Матрица, отсортированная по спирали: \n";
    for (int i = 0; i < strok; i++) {
        for (int j = 0; j < stolb; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
