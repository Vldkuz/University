#include "Uravnenie.h"

double Square(double x)
{
	return x * x - 3;
}

int main()
{
	double a, b,epsilon;
	std::cin >> a >> b >> epsilon;

	Segment My_Segment(a, b);
	Uravnenie My_Uravn(Square,My_Segment, epsilon);

	My_Uravn.ShowRoot(std::cout);
	return 0;
}