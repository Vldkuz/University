#pragma once
#include <fstream>

struct Matrix {
	Matrix(size_t order);
	Matrix(Matrix& A);
	double** matrix;
	size_t order;
	~Matrix();

};

struct Column {
	Column(size_t size);
	Column(Column& A);
	double* arr;
	size_t size;
	~Column();
};

struct LinearSys
{
	LinearSys();
	LinearSys(size_t order);
	Matrix *main;
	Column *leisure_factors;
	~LinearSys();    
};

class LinearSystemWork {
public:
	LinearSystemWork(std::ifstream& file);
	void GetMainSystemMat();
	size_t GetCountUnknown();
	double GetDetMainMatrix();
	double GetDetExtMatrix(size_t j);
	~LinearSystemWork();
private:
	LinearSys* MainSystem;
};