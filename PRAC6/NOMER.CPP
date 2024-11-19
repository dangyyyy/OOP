#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Store {
public:
    string name;
    string address;
    string workingHours;

    Store() 
        : name("Без названия"), address("Без адреса"), workingHours("Не указан") {}
    Store(const string& storeName, const string& storeHours)
        : name(storeName), address("Без адреса"), workingHours(storeHours) {}
    Store(const string& storeName, const string& storeAddress, const string& storeHours)
        : name(storeName), address(storeAddress), workingHours(storeHours) {}

    // Функция для установки адреса
    void setAddress(const string& newAddress) {
        address = newAddress;
    }

    // Функция для установки графика работы
    void setWorkingHours(const string& newHours) {
        workingHours = newHours;
    }

    // Функция для получения информации о магазине
    string getInfo() const {
        return "Название: " + name + "\nАдрес: " + address + "\nГрафик работы: " + workingHours;
    }

    // Функция для определения популярности магазина
    string getPopularity(int dailyCustomers) const {
        if (dailyCustomers < 20) {
            return "Низкая популярность";
        }
        else if (dailyCustomers < 100) {
            return "Средняя популярность";
        }
        else {
            return "Высокая популярность";
        }
    }

    // Функция для расчета примерной выручки
    double calculateRevenue(double averageCheck, int dailyCustomers) const {
        return averageCheck * dailyCustomers;
    }

    // Функция для вывода информации о магазине
    void printInfo() const {
        cout << "Магазин: " << name << endl;
        cout << "Адрес: " << address << endl;
        cout << "График работы: " << workingHours << endl;
    }

    // Перегруженная функция для вывода информации с популярностью
    void printInfo(int dailyCustomers) const {
        printInfo();
        cout << "Популярность: " << getPopularity(dailyCustomers) << endl;
    }
};

int main() {
    Store store1;
    store1.setWorkingHours("9:00 - 21:00");
    store1.printInfo();
    cout << endl;


    Store store2("Продуктовый рай", "8:00 - 22:00");
    store2.setAddress("ул. Мира, 5");
    store2.printInfo(45);
    cout << "Примерная выручка: " << fixed << setprecision(2)
        << store2.calculateRevenue(350.5, 45) << " рублей" << endl;
    cout << endl;


    Store store3("Магнит", "ул. Ленина, 10", "7:00 - 23:00");
    store3.printInfo(120);
    cout << "Примерная выручка: " << fixed << setprecision(2)
        << store3.calculateRevenue(420.0, 120) << " рублей" << endl;
    cout << endl;

}
