#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    string name1,name2,name3,sur1,sur2,sur3;
    int year1,year2,year3,mon1,mon2,mon3;
    cout << "Введите Имя и Фамилию, возраст пользователя 1 в годах и месяцах: " << endl;
    cin >> name1 >> sur1 >> year1 >> mon1;
    cout << "Введите Имя и Фамилию, возраст пользователя 2 в годах и месяцах: " << endl ;
    cin >> name2 >> sur2 >> year2 >> mon2;
    cout << "Введите Имя и Фамилию, возраст пользователя 3 в годах и месяцах: " << endl;
    cin >> name3 >> sur3 >> year3 >> mon3;
    cout << "---------------------------" << endl;
    cout << "ИМЯ" << "\t" << "\t" << "ФАМИЛИЯ" << "\t" << "\t" << "МЕСЯЦА" << "\t" << "\t" << "ДНИ" << endl;
    cout << name1 << "\t" << "\t" << sur1 << "\t" << "\t" << year1 * 12 + mon1 << "\t" << "\t" << (year1 * 12 + mon1) * 30 << endl;
    cout << name2 << "\t" << "\t" << sur2 << "\t" << "\t" << year2 * 12 + mon2 << "\t" << "\t" << (year2 * 12 + mon2) * 30 << endl;
    cout << name3 << "\t" << "\t" << sur3 << "\t" << "\t" << year3 * 12 + mon3 << "\t" << "\t" << (year3 * 12 + mon3) * 30 << endl;
}   
