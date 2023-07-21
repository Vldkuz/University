#include <iostream>

typedef double(*func)(double);

double Cub(double x)
{
	return x * x * x;
}

double Square(double x)
{
	return x * x - 5;
}

double Hyperbolic(double x)
{
	return 1 / x;
}

double IntegralB(double a, double b, double E, func f)
{
	double h = (b - a);
	double Image = f(a + h/2);

	double OldSumm = Image * h;
	double NewSumm = 0;
	
	while (abs(OldSumm - NewSumm) >= E)
	{
		OldSumm = NewSumm;
		Image = 0;

		h /= 2;
		for (double ptr = a + h / 2; ptr < b; ptr += h)
		{
			Image += f(ptr);
		}

		NewSumm = Image * h;
	}
	
	return NewSumm;
}

int main()
{
	double a, b, E, IntegralSummary;
	std::cin >> a >> b >> E;
	int NumberOfFunc;
	std::cin >> NumberOfFunc;

	if (NumberOfFunc == 1)
	{
		IntegralSummary = IntegralB(a, b, E, Cub);
	}
	else if (NumberOfFunc == 2)
	{
		IntegralSummary = IntegralB(a, b, E, Square);
	}
	else
	{
		IntegralSummary = IntegralB(a, b, E, Hyperbolic);
	}

	std::cout << IntegralSummary << std::endl;


	return 0;
}