#include <iostream>
using namespace std;

int main() {
    int num = 10; 
    int* ptr = &num; 
    int group = 6;
    *ptr += group; 
    cout << "Новое значение переменной: " << *ptr << endl; 

}
