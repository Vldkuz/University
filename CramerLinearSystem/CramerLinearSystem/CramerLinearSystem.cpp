#include <iostream>
#include "ClassLinearSys.h"


int main()
{
	std::ifstream file("Input.txt");
	LinearSystemWork System(file);
	file.close();

	double detM = System.GetDetMainMatrix();
	size_t count_unknown = System.GetCountUnknown();
	double* detS = new double[count_unknown];
	std::cout << detM << std::endl;
	for (size_t i = 0; i < count_unknown; ++i)
	{
		detS[i] = System.GetDetExtMatrix(i);
	}

	std::ofstream out("Output.txt");
	if (detM == 0)
	{
		for (size_t i = 0; i < count_unknown; ++i)
		{
			if (detS[i] != 0) {
				out << "No_solve" << std::endl;
				return 0;
			}
		}

		out << "Infinity Solutions" << std::endl;
	}
	else {
		for (size_t i = 0; i < count_unknown; ++i)
		{
			out << detS[i] / detM << " ";
		}
	}

	out.close();

	return 0;
}
