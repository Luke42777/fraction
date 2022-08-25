
#include "fraction.h"

Fraction::Fraction(int nom,int denom){
	mNominator = nom;
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
	first = Fraction(this->mNominator * (commonDenominator / this->mDenominator),commonDenominator);
	second = Fraction(other.mNominator * (commonDenominator / other.mDenominator),commonDenominator);
	return result.Simplify(Fraction(first.mNominator + second.mNominator,commonDenominator));
}
Fraction Fraction::Subtract(const Fraction& other) const{
	//reducing to a common denominator for calculation
		int commonDenominator = this->mDenominator * other.mDenominator;
		//defining two Fraction objects ( as we don't want to change data)
		Fraction first;
		Fraction second;
		Fraction result;
		first = Fraction(this->mNominator * (commonDenominator / this->mDenominator),commonDenominator);
		second = Fraction(other.mNominator * (commonDenominator / other.mDenominator),commonDenominator);
		return result.Simplify(Fraction(first.mNominator - second.mNominator,commonDenominator));
}
Fraction Fraction::Multiply(const Fraction& other) const{
	return Fraction(this->mNominator * other.mNominator, this->mDenominator * other.mDenominator );
}
Fraction Fraction::Divide(const Fraction& other) const{
	Fraction result;
	return result.Simplify(Fraction(this->mNominator * other.mDenominator, this->mDenominator * other.mNominator ));
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
		if((result.mDenominator < 0) || (result.mNominator < 0)){// in case one of them is'-' result will be negative fractial number
			signToReturn = -1; // to remember if one of them(nominator or denominator) is negative number
		}
		else{
			signToReturn = 1; //in case if it's positive
		}

		if (result.mDenominator < 0) { result.mDenominator *= -1; } // to make them positive for calculation
	    if (result.mNominator < 0)   { result.mNominator   *= -1; } //as above


	    for (int i = result.mNominator; i > 0; i--){

	    	if (( !(result.mNominator % i) ) && ( !(result.mDenominator % i))){
	    		result.mNominator = result.mNominator / i;
	    		result.mDenominator = result.mDenominator / i;

	            result.mNominator *= signToReturn;// in case 'frac' is negative number
	            return result;
	    	}

	    }
}

