#include <iostream>
using namespace std;

int main()
{
    int (*nom);
    *nom = 0;
    *nom += 6;
    cout << *nom << endl;
}