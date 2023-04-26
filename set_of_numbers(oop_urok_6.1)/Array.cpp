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
	bool flag;
	for (int i = 0; i < size; i++) {
		(arr[i] == value) ? flag = true : flag = false;
	}
	return flag;
}

void Array::operator+(const int& value)
{
	int* new_arr = new int[size + 1];
	if (ownership_check_array(value)) {
		for (int i = 0; i < size + 1; i++) {
			new_arr[i] = arr[i];
		}
		new_arr[size] = value;
	}
		
	
}

ostream& operator<< (ostream& output, Array& _arr) {
	output << _arr.to_print();
	return output;
}