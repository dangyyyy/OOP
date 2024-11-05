#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Введите количество строк: ";
    cin >> n;
    cin.ignore(); // Чтобы убрать символ новой строки после ввода числа

    vector<string> strings; 

    cout << "Введите строки:\n";
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        strings.push_back(str); 

        for (int j = strings.size() - 1; j > 0; j--) {
            if (strings[j] < strings[j - 1]) {
                string temp = strings[j];
                strings[j] = strings[j - 1];
                strings[j - 1] = temp;
            }
            else {
                break;
            }
        }
    }

    cout << "Отсортированные строки:\n";
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }

    return 0;
}
