#include <iostream>
using namespace std;
int findMax(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}
int findMax(int arr[], int size) {
    int maxElement = arr[0];  
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    return maxElement;
}

int main() {
    int num1, num2;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    int maxNum = findMax(num1, num2);
    cout << "Максимальное число: " << maxNum << endl;

    int arr[20], n;
    cout << "\nВведите количество элементов массива (не более 20): ";
    cin >> n;

    if (n > 0 and n <= 20) {
        cout << "Введите элементы массива: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int maxInArray = findMax(arr, n);
        cout << "Максимальный элемент массива: " << maxInArray << endl;
    }
    else {
        cout << "Некорректное количество элементов!" << endl;
    }

    return 0;
}
