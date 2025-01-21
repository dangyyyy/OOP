#pragma once

#include <string>
using namespace std;

class BaseStore {
public:
    virtual void printDetails() const = 0;
    virtual string getType() const = 0;
};

class Store : public BaseStore {
protected:
    string name, address, workingHours;

public:
    Store(const string& storeName, const string& storeAddress, const string& storeHours);

    void setAddress(const string& newAddress);
    string getAddress() const;

    void setWorkingHours(const string& newHours);
    string getWorkingHours() const;

    void printDetails() const override;
    string getType() const override;

    // Перегрузка операторов
    Store operator +(const Store& other) const;
    Store& operator+=(const Store& other);

    // Перегрузка операторов ++ (префиксный и постфиксный)
    Store& operator ++();      
    Store operator ++(int);     
};

class Warehouse : public BaseStore {
private:
    int capacity;

public:
    Warehouse(int cap = 0);

    void setCapacity(int cap);
    int getCapacity() const;

    void printDetails() const override;
    string getType() const override;

    bool operator==(const Warehouse& other) const;
    bool operator!=(const Warehouse& other) const;
};

class LogisticsStore : public Store, public Warehouse {
public:
    LogisticsStore(const string& storeName, const string& storeAddress, const string& storeHours, int capacity);

    void printDetails() const override;

    string getType() const override;

    LogisticsStore operator+(const LogisticsStore& other) const;
};
