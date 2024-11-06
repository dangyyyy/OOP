#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    int* elements = new int[n];
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    int max = *elements;
    for (int i = 1; i < n; i++) {
        if (*(elements + i) > max) {
            max = *(elements + i);
        }
    }
    cout << "Максимум: " << max << endl;
    delete[] elements;
    return 0;
}
