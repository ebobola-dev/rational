#include <iostream>
#include "RationalNum.h"

const int testSize = 9;

int test[2][testSize] = {
	{0,	 0,  -1,   2, -14, 113, 85,  -4,   1},
	{0,	-14, 16, -32,  0,  113,  5, -100, -25},
};

void printError(RationalError, bool = true);
char getCompSignAsChar(CompSign);

int main() {
	setlocale(LC_ALL, "RUS");
	RationalNum testArr[testSize];
	for (size_t i = 0; i < testSize; i++) {
		try {
			printf("��������: %d, %d, ���������: ", test[0][i], test[1][i]);
			RationalNum num(test[0][i], test[1][i]);
			std::cout << num << std::endl;
			testArr[i] = num;
		}
		catch (RationalError error) { printError(error); }
	}

	printf("\n���������� ������: [ ");
	for (size_t i = 0; i < testSize; i++) {
		std::cout << testArr[i] << ", ";
	}
	printf("]\n\n");

	printf("��������:\n");
	for (size_t i = 1; i < testSize; i++) {
		std::cout << testArr[i - 1] << " + " << testArr[i] << " = ";
		std::cout << testArr[i - 1] + testArr[i] << std::endl;
	}
	printf("\n");

	printf("���������:\n");
	for (size_t i = 1; i < testSize; i++) {
		std::cout << testArr[i - 1] << " - " << testArr[i] << " = ";
		std::cout << testArr[i - 1] - testArr[i] << std::endl;
	}
	printf("\n");

	printf("���������:\n");
	for (size_t i = 1; i < testSize; i++) {
		std::cout << testArr[i - 1] << " * " << testArr[i] << " = ";
		std::cout << testArr[i - 1] * testArr[i] << std::endl;
	}
	printf("\n");

	printf("�������:\n");
	for (size_t i = 1; i < testSize; i++) {
		std::cout << testArr[i - 1] << " / " << testArr[i] << " = ";
		try {
			std::cout << testArr[i - 1] / testArr[i] << std::endl;
		}
		catch (RationalError error) { printError(error); }
	}
	printf("\n");

	printf("���������(�� ���������):\n");
	for (size_t i = 1; i < testSize; i++) {
		if (testArr[i - 1] == testArr[i]) {
			std::cout << testArr[i - 1] << " == " << testArr[i] << std::endl;
		}
	}
	printf("\n");

	printf("���������(�� �����������):\n");
	for (size_t i = 1; i < testSize; i++) {
		std::cout << testArr[i - 1];
		printf(" %c ", getCompSignAsChar(testArr[i - 1].getComparisonSign(testArr[i])));
		std::cout << testArr[i] << std::endl;
	}
	printf("\n");

	return 0;
}

char getCompSignAsChar(CompSign sign) {
	switch (sign)
	{
	case CompSign::More:
		return '>';
	case CompSign::Less:
		return '<';
	case CompSign::Equals:
		return '=';
	}
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