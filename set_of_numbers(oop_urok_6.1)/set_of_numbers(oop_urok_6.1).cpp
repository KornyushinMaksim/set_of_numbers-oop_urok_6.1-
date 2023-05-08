#include <iostream>
#include "Array.h"
using namespace std;

void func_ownership_check_array(bool value) {
    if (!value) {
        cout << "Число принадлежит множеству";
    }
    else {
        cout << "Число не принадлежит множеству";
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
    cout << arr1 << endl << arr2 << endl;
    func_ownership_check_array(!arr1.ownership_check_array(3));//принадлежность
    cout << endl;
    Array arr3 = arr1 + arr2;//сложение множеств
    cout << arr3 << endl;
    arr1 - 4;//удаление числа из множества
    cout << arr1 << endl;
    Array arr4 = arr1 - arr2;//разность множеств
    cout << arr4 << endl;
    Array arr5 = arr1 * arr2;//пересечение множеств
    cout << arr5 << endl;
    Array arr6 = arr1;//присвоение множеству
    cout << arr6 << endl;
    string s = arr2 == arr2;
    cout << s;
}