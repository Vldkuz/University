#include <fstream>
#include "ClassPolygon.h"

int main()
{
	std::ifstream file("Input.txt");
	size_t n;
	file >> n;
	Polygon* arr = new Polygon[n];
	int k = 0;
	for (size_t i = 0; i < n; ++i)
	{
		file >> arr[i];
		if (arr[i].IsConvex())
			++k;
	}

	file.close();

	Polygon* arr_t = new Polygon[k];
	k = 0;
	for (size_t i = 0; i < n; ++i)
	{
		if (arr[i].IsConvex()) {
			arr_t[k] = arr[i]; arr_t[k].CalcMaxDiag(); arr_t[k].Perimeter(); arr_t[k].Square(); ++k;
		}
	}

	std::ofstream out("Out.txt");
	arr_t = Sort(arr_t, k);
	for (size_t i = 0; i < k; ++i)
		out << arr_t[i];

	out.close();
	return 0;
}