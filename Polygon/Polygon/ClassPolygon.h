#pragma once
#include <fstream>


struct Point 
{
	double x;
	double y;
	double Distance(const Point& d1);

};

class Polygon
{
public:
	Polygon();
	Polygon(const Polygon& arg);
	~Polygon();
	friend std::ifstream& operator>>(std::ifstream& in, Polygon& d1);
	friend std::ofstream& operator<<(std::ofstream& out, const Polygon& d1);
	void operator=(const Polygon& arg);
	bool IsConvex();
	double CalcMaxDiag();
	double Perimeter();
	double Square();
	friend Polygon* Sort(Polygon* arr, int size);
private:
	friend void qsort_p(Polygon* arr, int left, int right, size_t* indexes);
	double MaxD;
	double SquareT;
	double PerimeterT;
	size_t n;
	Point* arr;
};



