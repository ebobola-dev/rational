#pragma once
#include <iostream>
#include <math.h>

#include "Errors.h"
#include "CompSigns.h"

class RationalNum {
	int q;
	int p;

	void _reduce(int&, int&) const;
	uint32_t _findGCD(int, int) const;
	uint32_t _findLCM(int, int) const;

public:
	RationalNum();
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
	bool isInt() const;
	bool isProper() const;
	CompSign getComparisonSign(const RationalNum&) const;
	//int getIntPart() const;
	//int getQWithoutIntPart() const;
};

