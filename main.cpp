#include <iostream>
#include "fraction.h"

int main() {
	fraction frac1;
	fraction frac2(2,3);
	fraction frac3(3,5);
	frac1 +=3;
	frac2 = frac2 + frac1-2;
	fraction frac4 = frac2 * frac3;
	frac1.print();
	frac2.print();
	frac3.print();
	frac4.print();
	return 0;
}
