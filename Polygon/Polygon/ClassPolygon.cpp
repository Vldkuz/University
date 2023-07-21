#include "ClassPolygon.h"

Polygon::~Polygon()
{
	delete[] arr;
	n = 0;
}

void Polygon::operator=(const Polygon& arg)
{
	n = arg.n;
	MaxD = arg.MaxD;
	PerimeterT = arg.PerimeterT;
	SquareT = arg.SquareT;
	delete[] arr;
	arr = new Point[arg.n];
	memcpy(arr, arg.arr, sizeof(Point) * n);
}

bool Polygon::IsConvex()
{
	for (size_t i = 0; i < n; ++i)
	{
		double det = arr[i].x * arr[(i + 1) % n].y + arr[(i + 1) % n].x * arr[(i + 2) % n].y + arr[i].y * arr[(i + 2) % n].x - arr[(i + 2) % n].x * arr[(i + 1) % n].y - arr[(i + 1) % n].x * arr[i].y - arr[(i + 2)% n].y * arr[i].x;
		if (det > 0)
			return false;
	}

	return true;
}

double Polygon::CalcMaxDiag()
{
	if (MaxD == -1) {
		double MaxD = 0;
		for (size_t i = 0; i < n - 2; ++i)
		{
			for (size_t j = i + 2; j < n; ++j)
			{
				if (i == 0) {
					if (j != n - 1) {
						MaxD = std::max(arr[i].Distance(arr[j]), MaxD);
					}
				}
				else
					if (j!= i - 1)
						MaxD = std::max(arr[i].Distance(arr[j]), MaxD);
			}
		}
		this->MaxD = MaxD;
	}

	return this->MaxD;
}

double Polygon::Perimeter()
{
	if (PerimeterT == -1)
	{
		double SumP = 0;
		for (size_t i = 0; i < n; ++i)
			SumP += arr[i].Distance(arr[(i + 1) % n]);
		PerimeterT = SumP;
	}

	return PerimeterT;
}

double Polygon::Square()
{
	if (SquareT == -1) {
		double SumMultPlus{ 0 }, SumMultMin{ 0 };
		for (size_t i = 0; i < n ; ++i)
		{
			SumMultPlus += arr[i].x * arr[(i + 1)% n].y;
			SumMultMin += arr[i].y * arr[(i + 1) % n].x;
		}

		SquareT = abs(SumMultPlus - SumMultMin) / 2.0;
	}

	return SquareT;
}

Polygon* Sort(Polygon* arr, int size)
{
	size_t* index = new size_t[size];
	for (size_t i = 0; i < size; ++i)
		index[i] = i;

	qsort_p(arr, 0, size - 1, index);
	Polygon* tem = new Polygon[size];
	for (size_t i = 0; i < size; ++i)
		tem[i] = arr[index[i]];

	delete[] arr;
	return tem;
}

void qsort_p(Polygon* arr, int left, int right, size_t* indexes)
{
	int l = left;
	int r = right;
	
	double mid = arr[indexes[(l + r) / 2]].MaxD;

	while (l <= r)
	{
		while (arr[indexes[l]].MaxD > mid)
			++l;
		while (arr[indexes[r]].MaxD < mid)
			--r;
		if (l <= r)
			std::swap(indexes[l++], indexes[r--]);
	}

	if (l < right)
		qsort_p(arr, l, right, indexes);
	if (r > left)
		qsort_p(arr, left, r, indexes);
}

Polygon::Polygon()
{
	n = 0;
	arr = nullptr;
	MaxD = -1;
	SquareT = -1;
	PerimeterT = -1;
}

Polygon::Polygon(const Polygon& arg)
{
	n = arg.n;
	MaxD = arg.MaxD;
	PerimeterT = arg.PerimeterT;
	SquareT = arg.SquareT;
	delete[] arr;
	arr = new Point[arg.n];
	memcpy(arr, arg.arr, sizeof(Point) * n);

}

std::ifstream& operator>>(std::ifstream& in, Polygon& d1)
{
	in >> d1.n;
	d1.arr = new Point[d1.n];
	for (size_t i = 0; i < d1.n; ++i)
		in >> d1.arr[i].x >> d1.arr[i].y;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Polygon& d1)
{
	out << d1.n <<" "<< d1.MaxD <<" "<< d1.PerimeterT <<" "<<d1.SquareT<< std::endl;
	for (size_t i = 0; i < d1.n; ++i)
		out << d1.arr[i].x << " " << d1.arr[i].y << std::endl;

	return out;
}

double Point::Distance(const Point& d1)
{
	return sqrt((x - d1.x) * (x - d1.x) + (y - d1.y) * (y - d1.y));
}
