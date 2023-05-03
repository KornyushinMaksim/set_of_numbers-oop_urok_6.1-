#include <iostream>
#include "Array.h"
using namespace std;

void func_ownership_check_array(bool value) {
    if (value) {
        cout << "Число принадлежит множеству!";
    }
    else {
        cout << "Число непринадлежит множеству!";
    }
}

int main()
{
    system("chcp 1251>nul");
    //srand(time(NULL));
    int size1, size2;
    cout << "Введите размеры: " << endl;
    cin >> size1 >> size2;
    Array arr1(size1);
    Array arr2(size2);
    arr1 + 3;//добавление элемента
    func_ownership_check_array(!arr1.ownership_check_array(3));//принадлежность
    cout << endl;
    //cout << arr1.to_print() << endl;
    Array arr3;
    arr3 = arr1 + arr2;
    cout << arr1 << endl << arr2 << endl << arr3;

}