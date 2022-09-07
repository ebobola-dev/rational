#include <iostream>
#include "RationalNum.h"

const int testSize = 8;

int test[2][testSize] = {
	{0,	 0,  -1,   2, -14, 113, 85,  -4},
	{0,	-14, 16, -32,  0,  113,  5, -100},
};

void printError(RationalError error, bool newLine = true);

int main() {
	setlocale(LC_ALL, "RUS");
	for (size_t i = 0; i < testSize; i++) {
		try {
			printf("��������: %d, %d, ���������: ", test[0][i], test[1][i]);
			RationalNum num(test[0][i], test[1][i]);
			std::cout << num << std::endl;
		}
		catch (RationalError error) { printError(error); }
	}
	return 0;
}

void printError(RationalError error, bool newLine) {
	std::cout << "������: ";
	switch (error) {
	case RationalError::NegativeQ:
		std::cout << "������������� �����������";
		break;
	case RationalError::DivisionByZero:
		std::cout << "������� �� ����";
		break;
	}
	if (newLine)
		std::cout << std::endl;
}