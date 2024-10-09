#include <iostream>
using namespace std;

int main() {
    const int msize = 20; 
    int numbers[msize];    
    int k;                

    cout << "Введите количество чисел (не более 20): ";
    cin >> k;

    cout << "Введите " << k << " чисел:" << endl;
    for (int i = 0; i < k; i++) {
        cin >> numbers[i];
    }
    int maxn = numbers[0]; 
    int maxi = 0;           

    for (int i = 1; i < k; i++) {
        if (numbers[i] > maxn) {
            maxn = numbers[i]; 
            maxi = i;            
        }
    }


    cout << "Наибольшее число: " << maxn << endl;
    cout << "Индекс наибольшего числа в массиве: " << maxi << endl;

    return 0;
}
