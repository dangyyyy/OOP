#include <iostream>
#include <string>
#include <windows.h>;
using namespace std;

int main() {
    char bukva = 'Л';
    char bukvaL = 'л';

    string stroka;
    cout << "Введите строку: ";
    getline(cin, stroka);

    int count = 0;
    for (int i = 0; i != stroka.length(); i++) {
        if (stroka[i] == bukva || stroka[i] == bukvaL) {
            count++;
        }
    }

    cout << "Буква Л встречается " << count << " раз(а) в строке." << endl;

    return 0;
}
