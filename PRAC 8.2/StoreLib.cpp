#include "StoreLib.h"
#include <iostream>

Store::Store(const string& storeName, const string& storeAddress, const string& storeHours)
    : name(storeName), address(storeAddress), workingHours(storeHours) {}

void Store::setAddress(const string& newAddress) {
    address = newAddress.empty() ? "Без адреса" : newAddress;
}

string Store::getAddress() const {
    return address;
}

void Store::setWorkingHours(const string& newHours) {
    workingHours = newHours.empty() ? "Не указан" : newHours;
}

string Store::getWorkingHours() const {
    return workingHours;
}

void Store::printDetails() const {
    cout << "=== Информация о магазине ===\n";
    cout << "Тип: " << getType() << "\n";
    cout << "Магазин: " << name << "\nАдрес: " << address << "\nГрафик работы: " << workingHours << endl;
    cout << "=============================\n";
}

string Store::getType() const {
    return "Обычный магазин";
}

Store Store::operator +(const Store& other) const {
    return Store(name + " + " + other.name, address, workingHours);
}

Store& Store::operator+=(const Store& other) {
    name += " + " + other.name;
    return *this;
}

Store& Store::operator ++() {
    workingHours += " (Дополнительные часы работы до 00:00)";
    return *this;
}

Store Store::operator ++(int) {
    Store temp = *this;
    ++(*this);
    return temp;
}

Warehouse::Warehouse(int cap)
    : capacity(cap > 0 ? cap : 0) {}

void Warehouse::setCapacity(int cap) {
    if (cap > 0) capacity = cap;
}

int Warehouse::getCapacity() const {
    return capacity;
}

void Warehouse::printDetails() const {
    cout << "=== Информация о складе ===\n";
    cout << "Тип: " << getType() << "\n";
    cout << "Вместимость: " << capacity << " единиц\n";
    cout << "===========================\n";
}

string Warehouse::getType() const {
    return "Складской объект";
}

bool Warehouse::operator==(const Warehouse& other) const {
    return capacity == other.capacity;
}

bool Warehouse::operator!=(const Warehouse& other) const {
    return !(*this == other);
}

LogisticsStore::LogisticsStore(const string& storeName, const string& storeAddress, const string& storeHours, int capacity)
    : Store(storeName, storeAddress, storeHours), Warehouse(capacity) {}

void LogisticsStore::printDetails() const {
    cout << "=== Информация о логистическом магазине ===\n";
    cout << "Тип: " << getType() << "\n";
    Store::printDetails(); // Используем базовый вывод из Store
    cout << "Вместимость склада: " << getCapacity() << " единиц\n";
    cout << "==========================================\n";
}

string LogisticsStore::getType() const {
    return "Логистический магазин";
}

LogisticsStore LogisticsStore::operator+(const LogisticsStore& other) const {
    return LogisticsStore(name + " + " + other.name, address, workingHours, getCapacity() + other.getCapacity());
}
