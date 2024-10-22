#include <iostream>
using namespace std;

void inputArray(int arr[], int& size) {
    cout << "Введите количество элементов массива (не более 20): ";
    cin >> size;
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    int arr[20];
    int n;      

    inputArray(arr, n);
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
