class Fraction{

public:
	Fraction();
	Fraction(int nominator,int denominator);

	Fraction Add(const Fraction& other) const;
	Fraction Subtract(const Fraction& other) const;
	Fraction Multiply(const Fraction& other) const;
	Fraction Divide(const Fraction& other) const;

private:
	int mNominator;
	int mDenominator;
};
