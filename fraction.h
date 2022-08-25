#pragma once
#include <iostream>
using namespace std;

class Fraction{

public:
	Fraction();
	Fraction(int nominator,int denominator);

	Fraction Add(const Fraction& other) const;
	Fraction Subtract(const Fraction& other) const;
	Fraction Multiply(const Fraction& other) const;
	Fraction Divide(const Fraction& other) const;

	friend ostream& operator<<(ostream& os, const Fraction& f);
	Fraction operator=(const Fraction& other);
private:
	int mNominator;
	int mDenominator;
	Fraction Simplify(const Fraction& other);

};
