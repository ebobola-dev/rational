#include "RationalNum.h"

RationalNum::RationalNum(int value) {
	q = value;
	p = 1;
}

RationalNum::RationalNum(int q, int p) {
	if (!p)
		throw RationalError::NegativeQ;

	_reduce(q, p);

	if (p < 0) {
		this->q = -q;
		this->p = -p;
	}
	else {
		this->q = q;
		this->p = p;
	}
}

RationalNum RationalNum::operator+(const RationalNum& num2) {
	if (p == num2.p) {
		return RationalNum(
			q + num2.q,
			p
		);
	}
	int lcmP = _findLCM(p, num2.p);
	return RationalNum(
		q * (lcmP / p) + num2.q * (lcmP / num2.p),
		lcmP
	);
}

RationalNum RationalNum::operator-(const RationalNum& num2) {
	if (p == num2.p) {
		return RationalNum(
			q - num2.q,
			p
		);
	}
	int lcmP = _findLCM(p, num2.p);
	return RationalNum(
		q * (lcmP / p) - num2.q * (lcmP / num2.p),
		lcmP
	);
}

RationalNum RationalNum::operator*(const RationalNum& num2) {
	return RationalNum(
		q * num2.q,
		p * num2.p
	);
}

RationalNum RationalNum::operator/(const RationalNum& num2) {
	if (num2.isZero()) 
		throw RationalError::DivisionByZero;
	return RationalNum(
		q * num2.p,
		p * num2.q
	);
}

RationalNum& RationalNum::operator+=(const RationalNum& num2) {
	if (p == num2.p) {
		q += num2.q;
	}
	else {
		int lcmP = _findLCM(p, num2.p);
		q = q * (lcmP / p) + num2.q * (lcmP / num2.p);
		p = lcmP;
	}
	return *this;
}

RationalNum& RationalNum::operator-=(const RationalNum& num2) {
	if (p == num2.p) {
		q -= num2.q;
	}
	else {
		int lcmP = _findLCM(p, num2.p);
		q = q * (lcmP / p) - num2.q * (lcmP / num2.p);
		p = lcmP;
	}
	return *this;
}

RationalNum& RationalNum::operator*=(const RationalNum& num2) {
	q *= num2.q;
	p *= num2.p;
	return *this;
}

RationalNum& RationalNum::operator/=(const RationalNum& num2) {
	if (num2.isZero())
		throw RationalError::DivisionByZero;
	q *= num2.p;
	p *= num2.q;
	return *this;
}

bool RationalNum::operator==(const RationalNum& num2) const  {
	return q == num2.q && p == num2.p;
}

bool RationalNum::operator!=(const RationalNum& num2) const {
	return !((*this) == num2);
}

bool RationalNum::operator>(const RationalNum& num2) const {
	if (p == num2.p) {
		return q > num2.q;
	}
	int lcmP = _findLCM(p, num2.p);
	return q * (lcmP / p) > num2.q * (lcmP / num2.p);
}

bool RationalNum::operator<(const RationalNum& num2) const {
	if (p == num2.p) {
		return q < num2.q;
	}
	int lcmP = _findLCM(p, num2.p);
	return q * (lcmP / p) < num2.q * (lcmP / num2.p);
}

bool RationalNum::operator>=(const RationalNum& num2) const {
	return (*this) > num2 || (*this) == num2;
}

bool RationalNum::operator<=(const RationalNum& num2) const {
	return (*this) < num2 || (*this) == num2;
}

std::ostream& operator<<(std::ostream& os, const RationalNum& num) {
	if (num.isZero()) {
		os << '0';
	}
	else {
		if (num.isNegative()) {
			os << '-';
		}
		os << abs(num.q) << '/' << num.p;
	}
	return os;
}

std::istream& operator>>(std::istream& is, RationalNum& num) {
	is >> num.q >> num.p;
	return is;
}

int RationalNum::getP() const { return p; }
int RationalNum::getQ() const { return q; }

bool RationalNum::isNegative() const { return p < 0; }
bool RationalNum::isZero() const { return p == 0; }
bool RationalNum::isProper() const { return q < p; }
int RationalNum::getIntPart() const { return q / p; }
int RationalNum::getQWithoutIntPart() const { return q - q / p; }

void RationalNum::_reduce(int& q, int& p) const {
	int gcd = _findGCD(q, p);
	if (gcd) {
		q /= gcd;
		p /= gcd;
	}
}

int RationalNum::_findGCD(int a, int b) const {
	while (a != 0 && b != 0) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int RationalNum::_findLCM(int a, int b) const { return a * b / _findGCD(a, b); }