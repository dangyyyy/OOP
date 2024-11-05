#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    vector<int> elements(n);
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    int max = elements[0];
    for (int i = 1; i < n; i++) {
        if (elements[i] > max) {
            max = elements[i];
        }
    }

    cout << "Максимум: " << max << endl;
    return 0;
}
