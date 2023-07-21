#pragma once
#include <fstream>

struct Polynom{
	int* factors = nullptr;
	int degree = 0;
};

struct DividedPolynom {
	Polynom q;
	Polynom r;
};


Polynom InStreamPolynom(std::ifstream &FileStream);

void OutStreamPolynom(std::ofstream &FileStream,Polynom &d1);

Polynom GetFactorsDerivative(Polynom& d1);

int GetValuePolynomPoint(Polynom& d1, int point);

int GetDerivativePolynomPoint(Polynom& d1, int point);

Polynom SummPolynom(Polynom &d1, Polynom &d2);

Polynom DifferencePolynom(Polynom &d1, Polynom &d2);

Polynom MultipliedPolynom(Polynom &d1, Polynom &d2);

DividedPolynom DividePolynom(Polynom& d1, Polynom &d2 );



