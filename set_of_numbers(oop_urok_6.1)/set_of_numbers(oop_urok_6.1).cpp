#include <iostream>
#include "Array.h"
using namespace std;

void func_ownership_check_array(bool _arr) {
    if (_arr) {
        cout << "Число принадлежит множеству!";
    }
    else {
        cout << "Число непринадлежит множеству!";
    }
}

int main()
{
    system("chcp 1251>nul");
    int size1, size2;
    cout << "Введите размеры: " << endl;
    cin >> size1 >> size2;
    Array arr(size1);
    //Array arr(size2);
    //cout << arr.to_print() << endl;
    cout << arr;

}