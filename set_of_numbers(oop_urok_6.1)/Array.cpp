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
//------------------------------

//проверка принадлежности числа
bool Array::ownership_check_array(int value)
{
	bool flag{};
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			flag = true;
			break;
		}
		else {
			flag = false;
		}
	}
	return flag;
}
//-----------------------------

//добавление числа к множеству
void Array::operator+ (const int& value)
{
	int* new_arr_plus = new int[size + 1];
	if (!ownership_check_array(value)) {
		for (int i = 0; i < size; i++) {
			new_arr_plus[i] = arr[i];
		}
		new_arr_plus[size] = value;
		delete[] arr;
		arr = new_arr_plus;
		size++;
	}
}
void Array::operator+= (const int& value)
{
	int* new_arr_plus = new int[size + 1];
	if (!ownership_check_array(value)) {
		for (int i = 0; i < size; i++) {
			new_arr_plus[i] = arr[i];
		}
		new_arr_plus[size] = value;
		delete[] arr;
		arr = new_arr_plus;
		size++;
	}
}
//-----------------------------------

//сложение множеств
Array Array::operator+ (Array& other)
{
	Array* new_arr = new Array();
	for (int i = 0; i < size; i++) {
		if (!new_arr->ownership_check_array(arr[i])) {
			*new_arr + arr[i];
		}
	}
	for (int i = 0; i < other.size; i++) {
		if (!new_arr->ownership_check_array(other.arr[i])) {
			*new_arr + other.arr[i];
		}
	}
	return *new_arr;
}
Array Array::operator+= (Array& other)
{
	Array* new_arr = new Array();
	for (int i = 0; i < size; i++) {
		if (!new_arr->ownership_check_array(arr[i])) {
			*new_arr + arr[i];
		}
	}
	for (int i = 0; i < other.size; i++) {
		if (!new_arr->ownership_check_array(other.arr[i])) {
			*new_arr + other.arr[i];
		}
	}
	return *new_arr;
}
//----------------------------------

//удаление числа из множества
void Array::operator- (const int& value)
{
	int serial_number = 0;
	int* new_arr = new int[size - 1];
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			serial_number = i;
		}
	}
	for (int i = 0; i < serial_number; i++) {
		new_arr[i] = arr[i];
	}
	for (int i = serial_number + 1; i < size; i++) {
		new_arr[i - 1] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	size--;
}
void Array::operator-= (const int& value)
{
	int* new_arr = new int[size - 1];
	for (int i = 0, j = 0; i < size - 1; i++, j++) {
		if (arr[i] != value) {
			new_arr[i] = arr[j];
		}
		else {
			new_arr[i] = arr[++j];
		}
	}
	delete[] arr;
	arr = new_arr;
	size--;
}
//--------------------------------------

//разность множеств
Array Array::operator-(Array& other)
{
	Array* new_arr = new Array();
		for (int j = 0; j < other.size; j++) {
			if (!other.ownership_check_array(arr[j])) {
				*new_arr + arr[j];
			}
		}
	return *new_arr;
}
Array Array::operator-=(Array& other)
{
	Array* new_arr = new Array();
		for (int j = 0; j < other.size; j++) {
			if (!other.ownership_check_array(arr[j])) {
				*new_arr + arr[j];
			}
		}
	return *new_arr;
}
//--------------------------------

//пересечение множеств
Array Array::operator* (Array& other)
{
	int counter = 0;
	Array* new_arr = new Array();
	for (int j = 0; j < other.size; j++) {
		if (other.ownership_check_array(arr[j])) {
			*new_arr + arr[j];
		}
	}
	return *new_arr;
}
Array Array::operator*= (Array& other)
{
	int counter = 0;
	Array* new_arr = new Array();
	for (int j = 0; j < other.size; j++) {
		if (other.ownership_check_array(arr[j])) {
			*new_arr + arr[j];
		}
	}
	return *new_arr;
}
//-----------------------------------

//присваивание
Array Array::operator=(Array& other)
{
	Array* new_arr = new Array();
	for (int i = 0; i < other.size; i++) {
		*new_arr + other.arr[i];
	}
	return *new_arr;
}
//------------------------------------

//сравнение
string Array::operator==(Array& other)
{
	string s;
	for (int i = 0; i < other.size; i++) {
		if (!ownership_check_array(other.arr[i])) {
			s = "Множества не равны";
			break;
		}
		else {
			s = "Множества равны";
		}
	}
	return s;
}


ostream& operator<< (ostream& output, Array& arr) {
	output << arr.to_print();
	return output;
}