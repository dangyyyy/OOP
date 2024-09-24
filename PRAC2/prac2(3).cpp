#include <iostream>
using namespace std;

int main() {
    int num;
    int max_num; 

    cout << "Введите числа (завершите ввод нулем): " << endl;

    cin >> num;

    if (num == 0) {
        cout << "Числа не были введены." << endl;
    } else {
        max_num = num;
        while (true) {
            cin >> num;
            if (num == 0) {
                break;
            }
            if (num > max_num) {
                max_num = num;
            }
        }
        cout << "Наибольшее число: " << max_num << endl;
    }

}
