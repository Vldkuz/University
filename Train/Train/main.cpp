#include <iostream>
#include "ClassTrain.h"
#include "SortFunc.h"
#include <fstream>


int main()
{
	std::ifstream file("Input.txt");
	size_t n;
	file >> n;
	Train* arr = new Train[n];
	for (size_t i = 0; i < n; ++i)
		file >> arr[i];
	file.close();

	arr = Sort(arr, n);
	
	std::ofstream out("Out.txt");
	for (size_t i = 0; i < n; ++i)
		out << arr[i];

	return 0;
}