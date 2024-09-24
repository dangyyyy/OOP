#include <iostream>
#include <string>
using namespace std;

int main() {
    string user1_login = "user1";
    string user1_password = "password1";

    string user2_login = "user2";
    string user2_password = "password2";

    string input_login, input_password;
    int attempts = 3; 

    while (attempts > 0) {
        cout << "Введите логин: ";
        cin >> input_login;
        
        cout << "Введите пароль: ";
        cin >> input_password;

        if ((input_login == user1_login and input_password == user1_password) or
            (input_login == user2_login and input_password == user2_password)) {
            cout << "Логин и пароль верны!" << endl;
            break;
        } else {
            cout << "Неверная пара логин-пароль!" << endl;
            attempts--; 
            if (attempts > 0) {
                cout << "Осталось попыток: " << attempts << endl;
            } else {
                cout << "Все попытки исчерпаны." << endl;
            }
        }
    }

}
