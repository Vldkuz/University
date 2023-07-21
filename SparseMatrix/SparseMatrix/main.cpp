#include "SparsedMatrix.h"
#include <fstream>

int main()
{
	std::ifstream file("Input.txt");
	std::ofstream Out("Output.txt");

	SparsedMatrix Matrix1;
	SparsedMatrix Matrix2;
	file >> Matrix1;
	file >> Matrix2;
	
	SparsedMatrix Matrix3;
	Matrix3 = Matrix1 + Matrix2;
	SparsedMatrix Matrix4;
	Matrix4 = Matrix1 * Matrix2;
	Out << Matrix3;
	Out << std::endl;
	Out << Matrix4;


	return 0;
}