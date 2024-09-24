#include <iostream>
using namespace std;

int main() {
    int kol; 
    int num; 
    int max_num; 

    cout << "Введите количество чисел: ";
    cin >> kol;

    cout << "Введите числа: ";

    cin >> num;
    max_num = num;

    for (int i = 1; i < kol; ++i) {
        cin >> num;
        if (num > max_num) {
            max_num = num;
        }
    }

    cout << "Наибольшее число: " << max_num << endl;

}
