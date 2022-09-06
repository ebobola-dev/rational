#pragma once
#include <iostream>
#include <math.h>

#include "errors.h"

class RationalNum {
	int q;
	int p;

	void _reduce(int&, int&) const;
	int _findGCD(int, int) const;
	int _findLCM(int, int) const;

public:
	RationalNum(int);
	RationalNum(int, int);

	RationalNum operator+(const RationalNum&);
	RationalNum operator-(const RationalNum&);
	RationalNum operator*(const RationalNum&);
	RationalNum operator/(const RationalNum&);

	RationalNum& operator+=(const RationalNum&);
	RationalNum& operator-=(const RationalNum&);
	RationalNum& operator*=(const RationalNum&);
	RationalNum& operator/=(const RationalNum&);

	bool operator==(const RationalNum&) const;
	bool operator!=(const RationalNum&) const;
	bool operator>(const RationalNum&) const;
	bool operator<(const RationalNum&) const;
	bool operator>=(const RationalNum&) const;
	bool operator<=(const RationalNum&) const;

	friend std::ostream& operator<<(std::ostream& , const RationalNum&);
	friend std::istream& operator>>(std::istream&, RationalNum&);

	int getP() const;
	int getQ() const;

	bool isNegative() const;
	bool isZero() const;
	bool isProper() const;
	int getIntPart() const;
	int getQWithoutIntPart() const;
};

