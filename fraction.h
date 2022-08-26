#pragma once
#include <iostream>
using namespace std;

class Fraction{

public:
	static Fraction sHalf;
	static Fraction sThird;
	static Fraction sFourth;
	static Fraction sFifth;

	Fraction();
	Fraction(int nominator,int denominator);

	Fraction Add(const Fraction& other) const;
	Fraction Subtract(const Fraction& other) const;
	Fraction Multiply(const Fraction& other) const;
	Fraction Divide(const Fraction& other) const;

	friend ostream& operator<<(ostream& os, const Fraction& f);
	Fraction operator=(const Fraction& other);

	inline int GetNumerator(){ return mNumerator;}
	inline int GetDenominator(){ return mDenominator;}


private:

	int mNumerator;
	int mDenominator;
	Fraction Simplify(const Fraction& other)const;

};
