#include <iostream>
#include "ArrayList.h"

int main()
{
	SortedArr d1;
	SortedArr d2;

	for (size_t i = 0; i < 10; ++i){
		d1.Append(i);
	}

	
	d1.ShowArray();

	for (size_t i = 2; i < 15; i+=2) {
		d2.Append(i);
	}

	d2.ShowArray();

	SortedArr d3;
	d3 = d1 + d2;

	d3.ShowArray();

	return 0;
}