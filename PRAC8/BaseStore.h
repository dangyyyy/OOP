#pragma once

#include <string>
using namespace std;

// Абстрактный класс для всех типов магазинов/складов
class BaseStore {
public:
    // Чисто виртуальная функция для вывода деталей
    virtual void printDetails() const = 0;

    // Новый метод для получения типа объекта
    virtual string getType() const = 0;

    virtual ~BaseStore() = default;
};

