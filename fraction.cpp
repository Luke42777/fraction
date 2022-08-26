
#include "fraction.h"

Fraction Fraction::sHalf = Fraction(1,2);
Fraction Fraction::sThird = Fraction(1,3);
Fraction Fraction::sFourth = Fraction(1,4);
Fraction Fraction::sFifth = Fraction(1,5);


Fraction::Fraction(int nom,int denom){
	mNumerator = nom;
	mDenominator = denom;
}

Fraction::Fraction():Fraction(0,1){}

Fraction Fraction::Add(const Fraction& other) const{
	//reducing to a common denominator for calculation
	int commonDenominator = this->mDenominator * other.mDenominator;
	//defining two Fraction objects ( as we don't want to change data)
	Fraction first;
	Fraction second;
	Fraction result;
	first = Fraction(this->mNumerator * (commonDenominator / this->mDenominator),commonDenominator);
	second = Fraction(other.mNumerator * (commonDenominator / other.mDenominator),commonDenominator);
	return result.Simplify(Fraction(first.mNumerator + second.mNumerator,commonDenominator));
}
Fraction Fraction::Subtract(const Fraction& other) const{
	//reducing to a common denominator for calculation
		int commonDenominator = this->mDenominator * other.mDenominator;
		//defining two Fraction objects ( as we don't want to change data)
		Fraction first;
		Fraction second;
		Fraction result;
		first = Fraction(this->mNumerator * (commonDenominator / this->mDenominator),commonDenominator);
		second = Fraction(other.mNumerator * (commonDenominator / other.mDenominator),commonDenominator);
		return result.Simplify(Fraction(first.mNumerator - second.mNumerator,commonDenominator));
}
Fraction Fraction::Multiply(const Fraction& other) const{
	return Fraction(this->mNumerator * other.mNumerator, this->mDenominator * other.mDenominator );
}
Fraction Fraction::Divide(const Fraction& other) const{
	Fraction result;
	return result.Simplify(Fraction(this->mNumerator * other.mDenominator, this->mDenominator * other.mNumerator ));
}

ostream& operator<<(ostream& os, const Fraction& f){
    os <<"\"" <<f.mNumerator << '/' << f.mDenominator << '\"' << endl;
    return os;
}
Fraction Fraction::operator=(const Fraction& other){
	return Fraction(this-> mNumerator = other.mNumerator,this->mDenominator = other.mDenominator);
}

Fraction Fraction::Simplify(const Fraction& frac)const{
		Fraction result = frac;
		//'-' sign causing problems in calculation below
	    int  signToReturn{0};
		if((result.mDenominator < 0) || (result.mNumerator < 0)){// in case one of them is'-' result will be negative fractial number
			signToReturn = -1; // to remember if one of them(nominator or denominator) is negative number
		}
		else{
			signToReturn = 1; //in case if it's positive
		}

		if (result.mDenominator < 0) { result.mDenominator *= -1; } // to make them positive for calculation
	    if (result.mNumerator < 0)   { result.mNumerator   *= -1; } //as above


	    for (int i = result.mNumerator; i > 0; i--){

	    	if (( !(result.mNumerator % i) ) && ( !(result.mDenominator % i))){
	    		result.mNumerator = result.mNumerator / i;
	    		result.mDenominator = result.mDenominator / i;

	            result.mNumerator *= signToReturn;// in case 'frac' is negative number
	            return result;
	    	}


	    }
	    return result;
}

