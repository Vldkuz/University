#include "ClassPolynom.h"

int main()
{
	Polynom d1;
	d1.add(1);
	d1.add(2);
	d1.add(3);

	Polynom d2;
	d2.add(1);
	d2.add(2);
	d2.add(3);

	Polynom *d3;
	d3 = d2 + d1;

	Polynom *d4;
	d4 = d2 * d1;

	d3->ShowPolynom();
	d4->ShowPolynom();


	return 0;
}