#include "RationalNum.h"

RationalNum::RationalNum(int value) {
	q = value;
	p = 1;
}

RationalNum::RationalNum(int q, int p) {
	if (p < 0) {
		this->q = -q;
		this->p = -p;
	}
	else if (p > 0) {
		this->q = q;
		this->p = p;
	}
	else {
		throw RationalError::NegativeQ;
	}
}

int RationalNum::getP() const { return p; }
int RationalNum::getQ() const { return q; }
bool RationalNum::isNegative() const { return p < 0; }

RationalNum RationalNum::operator+(const RationalNum& num2) {
	if (p == num2.p) {
		return RationalNum(
			q + num2.q,
			p
		);
	}
	return RationalNum(
		q * num2.p + num2.q * p,
		p * num2.p
	);
}

RationalNum RationalNum::operator-(const RationalNum& num2) {
	if (p == num2.p) {
		return RationalNum(
			q - num2.q,
			p
		);
	}
	return RationalNum(
		q * num2.p - num2.q * p,
		p * num2.p
	);
}

std::ostream& operator<<(std::ostream& os, const RationalNum& num) {
	if (num.q == 0) {
		os << '0';
	}
	else {
		if (num.isNegative()) {
			os << '-';
		}
		os << num.q << '/' << num.p;
	}
	return os;
}