#include "Array.h"

string Array::to_print()
{
	string s;
	for (int i = 0; i < this->size; i++) {
		s.append(to_string(this->arr[i]));
		s.append(" ");
	}
	
	return s;
}

bool Array::ownership_check_array(int value)
{
	bool flag{};
	for (int i = 0; i < size; i++) {
		(arr[i] == value) ? flag = true : flag = false;
	}
	return flag;
}

void Array::operator+(const int& value)
{
	int* new_arr = new int[size + 1];
	if (!ownership_check_array(value)) {
		for (int i = 0; i < size + 1; i++) {
			new_arr[i] = arr[i];
		}
		new_arr[size] = value;
		delete[] arr;
		arr = new_arr;
		size++;
	}
}

Array Array::operator+ (Array& other) {
	Array* new_arr = new Array();
	for (int i = 0; i < size; i++) {
		if (!new_arr->ownership_check_array(arr[i])) {
			new_arr[i] = arr[i];
		}
	}
	for (int i = 0; i < other.size; i++) {
		if (!new_arr->ownership_check_array(other.arr[i])) {
			new_arr[i + size] = other.arr[i];
		}
	}

	//int counter = 0;
	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < other.size; j++) {
	//		if (ownership_check_array(other.arr[j])) {
	//			counter++;
	//		}
	//	}
	//}
	//int all_size = size + other.size - counter;
	//Array* new_arr = new Array[all_size];
	//for (int i = 0; i < size; i++) {
	//	new_arr[i] = arr[i];
	//}
	//for (int i = size; i < all_size; i++) {
	//	if (!ownership_check_array(other.arr[i])) {
	//		new_arr[i] = other.arr[i];
	//	}
	//}
	return *new_arr;
}

ostream& operator<< (ostream& output, Array& _arr) {
	output << _arr.to_print();
	return output;
}