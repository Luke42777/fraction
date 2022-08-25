/*
 * fraction.cpp
 *
 *  Created on: 22 Aug 2022
 *      Author: Lukasz
 */
#include "fraction.h"

Fraction::Fraction(int nom,int denom){
	mNominator = nom;
	mDenominator = denom;
}

Fraction::Fraction():Fraction(0,1){}

Fraction Fraction::Add(const Fraction& other) const{
	return Fraction(this->mNominator + other.mNominator, this->mDenominator + other.mDenominator );
}
Fraction Fraction::Subtract(const Fraction& other) const{
	return Fraction(this->mNominator - other.mNominator, this->mDenominator - other.mDenominator );
}
Fraction Fraction::Multiply(const Fraction& other) const{
	return Fraction(this->mNominator * other.mNominator, this->mDenominator * other.mDenominator );
}
Fraction Fraction::Divide(const Fraction& other) const{
	return Fraction(this->mNominator / other.mNominator, this->mDenominator / other.mDenominator );
}

ostream& operator<<(ostream& os, const Fraction& f){
    os <<"\"" <<f.mNominator << '/' << f.mDenominator << '\"' << endl;
    return os;
}
Fraction Fraction::operator=(const Fraction& other){
	return Fraction(this-> mNominator = other.mNominator,this->mDenominator = other.mDenominator);
}

Fraction Fraction::Simplify(const Fraction& frac){
	Fraction result = frac;
	//'-' sign causing problems in calculation below
	int  signToReturn{0};
	if((result.mDenominator < 0) || (result.mNominator < 0))// in case one of them is'-' result will be negative fractial number

	{

	signToReturn = -1; // to remeber if one of them(numerator or denominator) is negative number

	}

	else

	{

	signToReturn = 1; //in case if it's positive

	}

	if (result.mDenominator < 0) { result.mDenominator *= -1; } // to make them positive for calculation

	    if (result.mNominator < 0)   { result.mNominator   *= -1; } //as above
}

