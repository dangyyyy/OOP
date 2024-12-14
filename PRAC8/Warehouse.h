#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "BaseStore.h"
#include <iostream>
using namespace std;

// Класс Warehouse (склад)
class Warehouse : public BaseStore {
private:
    int capacity; // Вместимость склада

public:
    Warehouse(int cap = 0) : capacity(cap > 0 ? cap : 0) {}

    void setCapacity(int cap) { if (cap > 0) capacity = cap; }
    int getCapacity() const { return capacity; }

    void printDetails() const override {
        cout << "=== Информация о складе ===\n";
        cout << "Тип: " << getType() << "\n";
        cout << "Вместимость: " << capacity << " единиц\n";
        cout << "===========================\n";
    }

    string getType() const override { return "Складской объект"; }

    // Перегрузка оператора ==: сравнивает вместимость
    bool operator==(const Warehouse& other) const { return capacity == other.capacity; }

    // Перегрузка оператора !=: обратное сравнение
    bool operator!=(const Warehouse& other) const { return !(*this == other); }
};

#endif
