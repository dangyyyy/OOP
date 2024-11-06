#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Введите количество строк: ";
    cin >> n;
    cin.ignore();
    vector<string> strings;
    for (int i = 0; i < n; i++) {
        string str;
        cout << "Введите " << i+1 << " строку: ";
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
    for (int i = 0; i < n; i++) {
        cout << strings[i] << endl;
    }
}
