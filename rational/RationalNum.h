#pragma once
#include <iostream>
#include "errors.h"

class RationalNum {
	int q;
	int p;

public:
	RationalNum(int);
	RationalNum(int, int);

	RationalNum operator+(const RationalNum& num2);
	RationalNum operator-(const RationalNum& num2);
	RationalNum operator*(const RationalNum& num2);
	RationalNum operator/(const RationalNum& num2);

	friend std::ostream& operator<<(std::ostream& , const RationalNum&);

	int getP() const;
	int getQ() const;

	bool isNegative() const;
	bool isZero() const;
};

