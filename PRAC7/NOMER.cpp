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
        }
        else {
            address = newAddress;
        }
    }

    string getAddress() const {
        return address;
    }

    void setWorkingHours(const string& newHours) {
        if (newHours.empty()) {
            workingHours = "Не указан";
        }
        else {
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

// класс GroceryStore
class GroceryStore : public Store {
protected:
    int numberOfSections;

public:
    GroceryStore(const string& storeName, const string& storeAddress, const string& storeHours, int sections)
        : Store(storeName, storeAddress, storeHours), numberOfSections(sections) {}

    void printInfo() const override {
        Store::printInfo();
        cout << "Количество отделов: " << numberOfSections << endl;
        
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

// Класс LogisticsStore, основанный на GroceryStore и Warehouse
class LogisticsStore : public GroceryStore, public Warehouse {
public:
    LogisticsStore(const string& storeName, const string& storeAddress, const string& storeHours, int sections, int cap)
        : GroceryStore(storeName, storeAddress, storeHours, sections), Warehouse(cap) {}


    void printInfo() const override {
        GroceryStore::printInfo();
        printWarehouseInfo();
        
    }
};

// Класс RegionalStore, наследующий LogisticsStore
class RegionalStore : private LogisticsStore {
public:
    RegionalStore(const string& storeAddress, const string& storeHours, int sections, int capacity)
        : LogisticsStore("Региональный магазин", storeAddress, storeHours, sections, capacity) {}

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
    Store store("Продуктовый рай", "ул. Мира, 5", "8:00 - 22:00");
    store.printInfo();
    cout << endl;

    LogisticsStore logistics("Склад-магазин", "ул. Заводская, 7", "9:00 - 18:00", 5, 500);
    logistics.printInfo();
    cout << endl;

    RegionalStore regional("ул. Центральная, 3", "9:00 - 20:00", 3, 300);
    regional.printRegionalInfo();

    regional.changeName("Магазин Сибирь");
    regional.printRegionalInfo();
    //cout << regional.name << endl;

    cout << endl;

    return 0;
}
