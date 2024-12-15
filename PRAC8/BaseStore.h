#pragma once

#include <string>
using namespace std;

class BaseStore {
public:
    virtual void printDetails() const = 0;

    virtual string getType() const = 0;

    virtual ~BaseStore() = default;
};

