#include "Dinamic_Structure.h"
#include <iostream>
constexpr auto SIZE = 10;

void Hoare_Sort(int* arr, unsigned int left, unsigned int right) {
	if (left >= right)
		return;

	int left_t = left;
	int right_t = right - 1;
	int opp = (left_t + right_t) / 2;
	
	while (left_t <= right_t) {
		while (arr[left_t] > arr[opp])
			left_t++;

		while (arr[right_t] < arr[opp])
			right_t--;

		if (left_t <= right_t) {
			std::swap(arr[left_t], arr[right_t]);
			left_t++;
			right_t--;
		}
	}

	Hoare_Sort(arr, left, right_t);
	Hoare_Sort(arr, left_t, right);
}

Dinamic_Structure::Dinamic_Structure()
{
	this->arr = new int[SIZE];
	this->size = SIZE;
}

void Dinamic_Structure::push_back(int& elem)
{
	if (this->counter > this->size - 1) {
		int* temp = new int[this->size * 2];
		std::memcpy(temp, this->arr, this->size);
		delete[] this->arr;
		this->arr = temp;
		this->size *= 2;
	}
	this->arr[this->counter++] = elem;
}

void Dinamic_Structure::push_front(int& elem)
{
	if (this->counter == 0) {
		this->arr[0] = elem;
		this->counter++;
	}
	else 
	{
		int* temp = new int[this->size + 1];
		std::memcpy(temp, this->arr, this->size);
		this->size++;
		for (int i = size - 1; i >= 1; --i) {
			temp[i] = temp[i - 1];
		}
		temp[0] = elem;
		delete[] this->arr;
		this->arr = temp;
	}
}

void Dinamic_Structure::delete_elem(unsigned int index)
{
	int* temp = new int[this->size - 1];
	int i = 0;
	while (i < index) {
		temp[i] = this->arr[i];
		++i;
	}

	this->size--;
	while (i < this->size - 1) {
		temp[i] = arr[i + 1];
		++i;
	}

	delete[] this->arr;
	this->arr = temp;
}

int Dinamic_Structure::get_size()
{
	return this->size;
}

int Dinamic_Structure::get_elem(int index)
{
	if (index < this->size) {
		return this->arr[index];
	}
}

const int* Dinamic_Structure::get_c_arr()
{
	return this->arr;
}

int Dinamic_Structure::get_max()
{
	int maxd = this->arr[0];

	for (int i = 0; i < this->size; ++i) {
		if (this->arr[i] > maxd)
			maxd = this->arr[i];
	}

	return maxd;
}

int Dinamic_Structure::get_min()
{
	int mind = this->arr[0];
	for (int i = 0; i < this->size; ++i) {
		if (this->arr[i] < mind)
			mind = this->arr[i];
	}

	return mind;
}

void Dinamic_Structure::sort_struct()
{
	Hoare_Sort(this->arr, 0, this->size - 1);
}

Dinamic_Structure::~Dinamic_Structure()
{
	this->size = 0;
	delete[] this->arr;
}
