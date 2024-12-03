#include <iostream>
#include <string>

using namespace std;

// Базовый класс Store
class Store {
private:
    string address;      
    string workingHours; 

protected:
    string name;

public:
    Store() : name("Без названия"), address("Без адреса"), workingHours("Не указан") {}
    Store(const string& storeName, const string& storeAddress, const string& storeHours)
        : name(storeName) {
        setAddress(storeAddress);
        setWorkingHours(storeHours);
    }

    void setAddress(const string& newAddress) {
        if (newAddress.empty()) {
            address = "Без адреса";
        } else {
            address = newAddress;
        }
    }

    string getAddress() const {
        return address;
    }

    void setWorkingHours(const string& newHours) {
        if (newHours.empty()) {
            workingHours = "Не указан";
        } else {
            workingHours = newHours;
        }
    }

    string getWorkingHours() const {
        return workingHours;
    }

    // Вывод информации о магазине
    virtual void printInfo() const {
        cout << "Магазин: " << name << endl;
        cout << "Адрес: " << address << endl;
        cout << "График работы: " << workingHours << endl;
    }
};

// Класс Warehouse для множественного наследования
class Warehouse {
private:
    int capacity;

public:
    Warehouse(int cap) : capacity(cap > 0 ? cap : 0) {}

    void setCapacity(int cap) {
        if (cap > 0) {
            capacity = cap;
        }
    }

    int getCapacity() const {
        return capacity;
    }

    // Вывод информации о складе
    void printWarehouseInfo() const {
        cout << "Вместимость склада: " << capacity << " единиц" << endl;
    }
};

// Класс LogisticsStore, основанный на двух других
class LogisticsStore : public Store, public Warehouse {
public:
    LogisticsStore(const string& storeName, const string& storeAddress, const string& storeHours, int cap)
        : Store(storeName, storeAddress, storeHours), Warehouse(cap) {}

    // Вывод информации
    void printInfo() const override {
        Store::printInfo();
        printWarehouseInfo();
    }
};

// Класс RegionalStore, наследующий LogisticsStore
class RegionalStore : public LogisticsStore {
public:
    // Конструктор
    RegionalStore(const string& storeAddress, const string& storeHours, int capacity)
        : LogisticsStore("Региональный магазин", storeAddress, storeHours, capacity) {}

    // Метод изменения имени магазина
    void changeName(const string& newName) {
        name = newName;
    }

    // Вывод информации о региональном магазине
    void printRegionalInfo() const {
        cout << "\nИнформация о региональном магазине:" << endl;
        cout << "Имя магазина: " << name << endl;
        // cout << "Имя магазина: " << address << endl;
    }
};

int main() {
    // Магазин с базовыми параметрами
    Store store("Продуктовый рай", "ул. Мира, 5", "8:00 - 22:00");
    store.printInfo();
    cout << endl;

    // Логистический магазин
    LogisticsStore logistics("Склад-магазин", "ул. Заводская, 7", "9:00 - 18:00", 500);
    logistics.printInfo();
    cout << endl;

    // Региональный магазин
    RegionalStore regional("ул. Центральная, 3", "9:00 - 20:00", 300);
    regional.printRegionalInfo();

    // Изменение имени через функцию
    regional.changeName("Магазин Сибирь");
    regional.printRegionalInfo();
    // cout << regional.name << endl;

    cout << endl;

    return 0;
}
