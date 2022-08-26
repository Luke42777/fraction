
#include <iostream>
#include "fraction.h"
using namespace std;


int main(){
	Fraction frac1 = Fraction::sHalf;
	Fraction frac2 = Fraction::sThird;
	Fraction frac3;

	frac3 = frac1.Subtract(frac2);
	cout << frac3;

}




