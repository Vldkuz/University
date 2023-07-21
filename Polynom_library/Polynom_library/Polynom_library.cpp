#include <iostream>
#include <fstream>
#include "Polynom_Functions.h"


int main()
{
    Polynom d1;
    Polynom d2;
    int point;
    std::cin >> point;

    std::ifstream Test("Test.txt");
    d1 = InStreamPolynom(Test);
    d2 = InStreamPolynom(Test);
    Test.close();

    Polynom d3 = SummPolynom(d1, d2);
    Polynom d4 = DifferencePolynom(d1, d2);
    Polynom d5 = MultipliedPolynom(d1, d2);
    DividedPolynom d6 = DividePolynom(d1, d2);
    Polynom d7 = GetFactorsDerivative(d1);
    int a = GetDerivativePolynomPoint(d1, point);
    int b = GetValuePolynomPoint(d1, point);

    std::ofstream Test1("Test1.txt");
    OutStreamPolynom(Test1,d3);
    OutStreamPolynom(Test1, d4);
    OutStreamPolynom(Test1, d5);
    OutStreamPolynom(Test1, d6.q);
    OutStreamPolynom(Test1, d6.r);
    OutStreamPolynom(Test1, d7);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}

