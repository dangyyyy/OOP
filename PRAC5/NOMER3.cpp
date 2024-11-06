#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Введите количество строк: ";
    cin >> n;
    cin.ignore();
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cout << "Введите строку: ";
        getline(cin, strings[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strings[j] > strings[j + 1]) {
                swap(strings[j], strings[j + 1]);
            }
        }
    }

    cout << "Отсортированные строки:" << endl;
    for (const string& s : strings) {
        cout << s << endl;
    }

    return 0;
}
