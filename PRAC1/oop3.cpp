#include <iostream>
using namespace std;

int main() {
    int a = 10;
    double b = 10.5;
    char c = 'A';

    int* aPTR = &a;
    double* bPTR = &b;
    char* cPTR = &c;

    cout << "Адрес a: " << aPTR << endl;
    cout << "Адрес b: " << bPTR << endl;
    cout << "Адрес c: " << (void*)cPTR << endl;

    cout << "Размер a: " << (char*)(aPTR + 1) - (char*)aPTR << " байт" << endl;
    cout << "Размер b: " << (char*)(bPTR + 1) - (char*)bPTR << " байт" << endl;
    cout << "Размер c: " << (char*)(cPTR + 1) - (char*)cPTR << " байт" << endl;

}