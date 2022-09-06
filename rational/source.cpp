#include <iostream>
#include "RationalNum.h"


int main() {
	RationalNum num1(-4, -5);
	RationalNum num2(8, -5);
	std::cout << num1 << std::endl << num2 << std::endl << std::endl;
	std::cout << num1 - num2 << std::endl;
	num1.getP();
	return 0;
}