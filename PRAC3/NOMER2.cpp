#include <iostream>
using namespace std;

int main() {
    const int msize = 20; 
    int matrix[msize][msize]; 
    int stolb, strok;                 

    cout << "Введите количество строк (не более 20): ";
    cin >> stolb;
    cout << "Введите количество столбцов (не более 20): ";
    cin >> strok;

    cout << "Введите элементы матрицы (" << stolb << " строк, " << strok << " столбцов):" << endl;
    for (int i = 0; i < stolb; i++) {
        for (int j = 0; j < strok; j++) {
            cin >> matrix[i][j];
        }
    }

    int strmin[msize]; 
    for (int i = 0; i < stolb; i++) {
        int minin = matrix[i][0]; 
        for (int j = 1; j < strok; j++) {
            if (matrix[i][j] < minin) {
                minin = matrix[i][j];
            }
        }
        strmin[i] = minin;
    }


    int maximum = strmin[0]; 
    for (int i = 1; i < stolb; i++) {
        if (strmin[i] > maximum) {
            maximum = strmin[i];
        }
    }

    cout << "Максимум среди построчных минимумов: " << maximum << endl;

    return 0;
}