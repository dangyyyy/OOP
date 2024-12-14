#ifndef LOGISTICSSTORE_H
#define LOGISTICSSTORE_H

#include "Store.h"
#include "Warehouse.h"

// Класс LogisticsStore (логистический магазин)
class LogisticsStore : public Store, public Warehouse {
public:
    LogisticsStore(const string& storeName, const string& storeAddress, const string& storeHours, int capacity)
        : Store(storeName, storeAddress, storeHours), Warehouse(capacity) {}

    void printDetails() const override {
        cout << "=== Информация о логистическом магазине ===\n";
        cout << "Тип: " << getType() << "\n";
        Store::printDetails(); // Используем базовый вывод из Store
        cout << "Вместимость склада: " << getCapacity() << " единиц\n";
        cout << "==========================================\n";
    }

    string getType() const override { return "Логистический магазин"; }

    // Перегрузка оператора +: объединяет логистические магазины
    LogisticsStore operator+(const LogisticsStore& other) const {
        return LogisticsStore(name + " + " + other.name, address, workingHours, getCapacity() + other.getCapacity());
    }
};

#endif
