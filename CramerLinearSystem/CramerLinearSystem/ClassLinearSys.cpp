#include "ClassLinearSys.h"
#include <cstringt.h>
#include <iostream>

double* SummStrScalar(double* first, double* second, double scale, size_t size) {
	for (size_t i = 0; i < size; ++i)
		second[i] += scale * first[i];
	return second;
}

void swapstr(double* &first, double* &second)
{
	double* temp = first;
	first = second;
	second = temp;
}

double GetDetMatrix(Matrix& temp) {
	size_t k = 0;

	for (size_t i = 0; i < temp.order; ++i)
	{
		for (size_t num_str = i + 1; num_str < temp.order; ++num_str) {
			if (temp.matrix[i][i] == 0)
			{
				size_t j = i + 1;
				for (; j < temp.order; ++j) {
					if (temp.matrix[j][i] != 0) {
						swapstr(temp.matrix[i], temp.matrix[j]);
						++k;
						break;
					}
				}
				if (j == temp.order)
					return 0;
			}

			double scale = -temp.matrix[num_str][i] / temp.matrix[i][i];
			temp.matrix[num_str] = SummStrScalar(temp.matrix[i], temp.matrix[num_str], scale, temp.order);
		}
	}

	double Det = (k % 2 == 0)? 1 : -1;
	for (size_t i = 0; i < temp.order; ++i)
	{
		Det *= temp.matrix[i][i];
	}

	if (Det == -0)
		Det = 0;

	return Det;
}

LinearSystemWork::LinearSystemWork(std::ifstream& file)
{
	size_t n;
	file >> n;
	this->MainSystem = new LinearSys(n);

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n + 1; ++j) {

			if (j == n)
				file >> this->MainSystem->leisure_factors->arr[i];
			else
				file >> this->MainSystem->main->matrix[i][j];
		}
	}
}

double LinearSystemWork::GetDetMainMatrix()
{
	Matrix temp(*(this->MainSystem->main));
	return GetDetMatrix(temp);
}

LinearSystemWork::~LinearSystemWork()
{
	this->MainSystem->~LinearSys();
}

void LinearSystemWork::GetMainSystemMat()
{
	for (size_t i = 0; i < this->MainSystem->main->order; ++i)
	{
		for (size_t j = 0; j < this->MainSystem->main->order + 1; ++j)
		{
			if (j == this->MainSystem->main->order)
				std::cout << this->MainSystem->leisure_factors->arr[i];
			else {
				std::cout << this->MainSystem->main->matrix[i][j];
			}
		}

		std::cout << std::endl;
	}
}

size_t LinearSystemWork::GetCountUnknown()
{
	return this->MainSystem->leisure_factors->size;
}

double LinearSystemWork::GetDetExtMatrix(size_t j)
{
	Matrix temp(*(this->MainSystem->main));
	for (size_t i = 0; i < temp.order; ++i)
		temp.matrix[i][j] = this->MainSystem->leisure_factors->arr[i];
	return GetDetMatrix(temp);
}


Matrix::Matrix(size_t order)
{
	this->order = order;
	this->matrix = new double* [order];
	for (size_t i = 0; i < order; ++i)
		this->matrix[i] = new double[order];
}

Matrix::Matrix(Matrix& A)
{
	this->order = A.order;
	this->matrix = new double* [order];
	for (size_t i = 0; i < order; ++i)
		this->matrix[i] = new double[order];

	for (size_t i = 0; i < A.order; ++i) {
		for (size_t j = 0; j < A.order; ++j) {
			this->matrix[i][j] = A.matrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < this->order; ++i)
		delete[] this->matrix[i];
	this->order = 0;
	delete[] this->matrix;
}



Column::Column(size_t size)
{
	this->arr = new double[size];
	this->size = size;
}

Column::Column(Column& A)
{
	this->size = A.size;
	this->arr = A.arr;
}

Column::~Column()
{
	this->size = 0;
	delete this->arr;
}

LinearSys::LinearSys()
{
	this->main = nullptr;
	this->leisure_factors = nullptr;
}

LinearSys::LinearSys(size_t order)
{
	this->main = new Matrix(order);
	this->leisure_factors = new Column(order);
}

LinearSys::~LinearSys()
{
	main->~Matrix();
	leisure_factors->~Column();
}
