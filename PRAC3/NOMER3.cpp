#include <iostream>
#include <string>
#include <windows.h>;
using namespace std;

int main() {
    char bukva = 'Л';

    string stroka;
    cout << "Введите строку: ";
    getline(cin, stroka);

    int count = 0;
    for (int i = 0; i != stroka.length(); i++) {
        if (stroka[i] == bukva || stroka[i] == towlower(bukva)) {
            count++;
        }
    }

    cout << "Буква '" << bukva << "' встречается " << count << " раз(а) в строке." << endl;

    return 0;
}
