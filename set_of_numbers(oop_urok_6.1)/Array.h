#pragma once
#include <iostream>
#include <string>
using namespace std;

class Array
{
private:
	int* arr;
	int size;
	friend ostream& operator<< (ostream& putput, Array& _arr);
public:
	Array() {
		arr = {nullptr};
		size = { 0 };
	};
	Array(int _size) {
		size = _size;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 10;
			for (int j = 0; j < i; j++) {
				if (arr[i] == arr[j]) {
					i--;
				}
			}
		}
	}
	Array(const Array& other) {
		this->size = other.size;
		int* _arr = new int[other.size];
		if (other.arr) {
			for (int i = 0; i < other.size; i++) {
				_arr[i] = other.arr[i];
			}
		}
	}
	~Array() {
		if (arr) {
			delete[] arr;
		}
	}

	string to_print();
	bool ownership_check_array(int value);//принадлежность множества
	void operator+ (const int& value);
	Array operator+ (Array& other);
};

