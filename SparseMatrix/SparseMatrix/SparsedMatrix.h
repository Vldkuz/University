#pragma once
#include "LinkedList.h"

class SparsedMatrix
{
public:
	SparsedMatrix();
	SparsedMatrix(const SparsedMatrix& Matrix); //Конструктор копирования 
	SparsedMatrix(double**const Matrix,const size_t n, const  size_t m); // Конструктор для оптимизированного хранения матрицы из двумерного массива 
	SparsedMatrix(const LinkedList& List, const size_t Rows,const size_t Columns);


	friend std::istream& operator>>(std::istream& in, SparsedMatrix& Matrix); // Ввод происходит согласно схеме Скаляр: ИндексСтроки : ИндексСтолбца до первого пустого двоеточия
	friend std::ostream& operator<<(std::ostream& out, SparsedMatrix& Matrix);

	SparsedMatrix operator+(const SparsedMatrix& Matrix);
	SparsedMatrix operator-(const SparsedMatrix& Matrix);
	SparsedMatrix operator*(const double& Scalar);
	SparsedMatrix operator*(const SparsedMatrix& Matrix);

	~SparsedMatrix();
private:
	LinkedList* List = nullptr;
	size_t Rows;
	size_t Columns;
};



