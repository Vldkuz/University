#include "Polynom_Functions.h"
#include <string>

unsigned int GetFactorsCount(std::string temp) {
	unsigned int count = 1;
	unsigned int size_temp = temp.length();

	for (int i = 0; i < size_temp; ++i) {
		if (temp[i] == ' ')
			++count;
	}

	return count;
}


Polynom InStreamPolynom(std::ifstream &FileStream)//Коэффициент при наибольшей степени первый
{
	Polynom d1;
	std::string str;
	getline(FileStream, str);
	unsigned int size_str = str.length();
	unsigned int factors_c = GetFactorsCount(str);
	unsigned int k = 0;
	//1 23 32 count_prob = n-1 // n = count_prob + 1
	// Доказывается по индукции

	int* factors = new int[factors_c];
	int d = 0;
	while (d < size_str) {
		std::string temp;
		while (str[d] != ' ' && d < size_str) {
			temp += str[d];
			++d;
		}

		factors[k++] = stoi(temp);
		++d;
	}

	d1.factors = factors;
	d1.degree = factors_c - 1;
	return d1;
}

void OutStreamPolynom(std::ofstream &FileStream,Polynom &d1)//Коэффициент при наибольшей степени первый
{
	FileStream << d1.degree << std::endl;
	
	for (int i = 0;i < d1.degree + 1; ++i) {
		FileStream << d1.factors[i] << " ";
	}
	FileStream << std::endl;
}

Polynom GetFactorsDerivative(Polynom& d1)
{
	Polynom d2;
	d2.degree = d1.degree - 1;
	d2.factors = new int[d1.degree];

	unsigned int k = 0;
	for (int i = 0; i < d1.degree + 1; ++i) {
		int d = (d1.degree - i) * d1.factors[i];
		d2.factors[k++] = d;
	}

	return d2;
}

int GetValuePolynomPoint(Polynom& d1, int point)
{
	int summ = 0;
	for (int i = 0; i < d1.degree + 1; ++i) {
		summ += pow(point, d1.degree - i) * d1.factors[i];
	}

	return summ;
}

int GetDerivativePolynomPoint(Polynom& d1, int point)
{
	Polynom d2 = GetFactorsDerivative(d1);
	return GetValuePolynomPoint(d2, point);
}

int GetDegreePolynomAndFactors(Polynom& d1) {

	for (int i = 0; i < d1.degree + 1; ++i) {
		if (d1.factors[i] != 0) {
			d1.degree -= i;
			d1.factors = &d1.factors[i];
			return d1.degree;
		}
	}

	d1.factors = &d1.factors[d1.degree];
	return 0;
}


Polynom SummPolynom(Polynom& d1, Polynom& d2)
{
	Polynom d3;
	unsigned int k = 0;
	d3.degree = std::max(d1.degree, d2.degree);
	d3.factors = new int[d3.degree + 1];

	int size_1 = d1.degree;
	int size_2 = d2.degree;


	for (int i = d3.degree; i >= 0; --i) {
		if (size_1 >= 0 && size_2 >= 0) {
			int temp = d2.factors[size_2--] + d1.factors[size_1--];
			d3.factors[i] = temp;
		}
		
		else if (size_1 >= 0 && size_2 < 0)
		{
			int temp = d1.factors[size_1--];
			d3.factors[i] = temp;
		}

		else if (size_2 >= 0 && size_1 < 0) {
			int temp = d2.factors[size_2--];
			d3.factors[i] = temp;
		}
	}

	d3.degree = GetDegreePolynomAndFactors(d3);

	//Придется пересчитать максимальную степень многочлена, поскольку может быть подан многочлен, обратный по сложению, что противоречит тому, что максимальная степень
	//многочлена будет равна максимимуму.

	return d3;
}

Polynom GetInversePolynom(Polynom &d1) { 
	Polynom temp;
	temp.degree = d1.degree;
	temp.factors = new int[d1.degree + 1];

	for (int i = 0; i < d1.degree + 1; ++i) {
		temp.factors[i] = -d1.factors[i];
	}

	return temp;
}

Polynom DifferencePolynom(Polynom& d1, Polynom& d2)
{
	Polynom temp = GetInversePolynom(d2);
	return SummPolynom(d1, temp);
}

Polynom MultipliedPolynom(Polynom& d1, Polynom& d2)
{
	Polynom d3;
	d3.degree = d1.degree + d2.degree;
	d3.factors = new int[d3.degree + 1] {0};


	for (int i = 0; i < d1.degree + 1; ++i) {
		for (int j = 0; j < d2.degree + 1; ++j) {
			d3.factors[i + j] += d1.factors[i] * d2.factors[j];
		}
	}

	return d3;
}

Polynom PreparedForDiv(Polynom& d1, unsigned int k) {
	Polynom d2;
	d2.degree = d1.degree;
	d2.factors = new int[d1.degree + 1] {0};
	d2.factors[k] = d1.factors[k];
	d2.degree = GetDegreePolynomAndFactors(d2);

	return d2;
}

DividedPolynom DividePolynom(Polynom& d1, Polynom& d2)
{
	DividedPolynom d3;
	Polynom delim = d1;
	Polynom divider = d2;
	Polynom chast;
	unsigned int size_f = d1.degree - d2.degree + 1;
	chast.factors = new int[size_f] {0};
	chast.degree = delim.degree - divider.degree;
	unsigned int k = 0;
	while (delim.degree >= divider.degree && k < size_f) {
		int ffactor = delim.factors[0] / divider.factors[0];
		chast.factors[k] = ffactor;
		if (ffactor == 0) delim.degree--;
		Polynom ForDiv = PreparedForDiv(chast, k);
		Polynom razn = MultipliedPolynom(divider, ForDiv);
		delim = DifferencePolynom(delim, razn);
		++k;
	}

	d3.q = chast;
	d3.r = delim;

	return d3;
}
