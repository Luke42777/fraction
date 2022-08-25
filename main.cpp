
#include <iostream>
#include "fraction.h"
using namespace std;


int main(){
	Fraction frac1(2,8);
	Fraction frac2(-4,8);
	Fraction frac3;

	frac3 = frac1.Divide(frac2);
	cout << frac3;

}




