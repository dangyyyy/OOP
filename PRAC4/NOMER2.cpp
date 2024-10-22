#include <iostream>
using namespace std;

void inputNumbers(int& a, int& b) {
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
}

int main() {
    int num1, num2;
    inputNumbers(num1, num2);

    if (num1 > num2) {
        cout << "Максимальное число: " << num1 << endl;
    }
    else {
        cout << "Максимальное число: " << num2 << endl;
    }

}
