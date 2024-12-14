#include <iostream>
#include "Store.h"
#include "Warehouse.h"
#include "LogisticsStore.h"
using namespace std;

int main() {
    Store store("Продуктовый рай", "ул. Мира, 5", "8:00 - 22:00");
    store.printDetails();

    cout << endl;

    Warehouse warehouse1(500), warehouse2(300);
    warehouse1.printDetails();
    warehouse2.printDetails();

    if (warehouse1 == warehouse2)
        cout << "Склады равны по вместимости.\n";
    else
        cout << "Склады имеют разную вместимость.\n";

    cout << endl;

    LogisticsStore logistics1("Склад-магазин", "ул. Заводская, 7", "9:00 - 18:00", 1000);
    LogisticsStore logistics2("Склад-Север", "ул. Транспортная, 10", "8:00 - 20:00", 500);
    logistics1.printDetails();
    logistics2.printDetails();

    LogisticsStore mergedLogistics = logistics1 + logistics2;
    mergedLogistics.printDetails();

    cout << endl;

    store += Store("Магазин у дома", "ул. Ленина, 10", "9:00 - 21:00");
    store.printDetails();

    ++store; // Префиксный оператор
    store.printDetails();

    return 0;
}
