#ifndef STORE_H
#define STORE_H

#include "BaseStore.h"
#include <iostream>
#include <string>
using namespace std;

// Класс Store (базовый магазин)
class Store : public BaseStore {
protected:
    string name, address, workingHours; // Имя, адрес и график работы

public:
    Store(const string& storeName = "Без названия", const string& storeAddress = "Без адреса", const string& storeHours = "Не указан")
        : name(storeName), address(storeAddress), workingHours(storeHours) { }

void setAddress(const string& newAddress) { address = newAddress.empty() ? "Без адреса" : newAddress; }
string getAddress() const { return address; }

    void setWorkingHours(const string& newHours) { workingHours = newHours.empty() ? "Не указан" : newHours; }
string getWorkingHours() const { return workingHours; }

    // Уникальная реализация printDetails
    void printDetails() const override {
        cout << "=== Информация о магазине ===\n";
cout << "Тип: " << getType() << "\n";
cout << "Магазин: " << name << "\nАдрес: " << address << "\nГрафик работы: " << workingHours << endl;
cout << "=============================\n";
    }

    string getType() const override { return "Обычный магазин"; }

    // Перегрузка оператора +: объединение магазинов по имени
    Store operator +(const Store& other) const { return Store(name + " + " + other.name, address, workingHours); }

    // Перегрузка оператора +=: добавляет имя другого магазина к текущему
    Store & operator+=(const Store& other) { name += " + " + other.name; return *this; }

// Перегрузка операторов ++ (префиксный и постфиксный)
Store & operator ++() { workingHours += " (расширенные часы)"; return *this; } // Префикс
Store operator ++(int) { Store temp = *this; ++(*this); return temp; }        // Постфикс
};

#endif
