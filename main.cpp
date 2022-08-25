
#include <iostream>
#include "fraction.h"
using namespace std;


int main(){
	Fraction frac1(1,2);
	Fraction frac2(1,3);
	Fraction frac3;

	frac3 = frac1.Subtract(frac2);
	cout << frac3;

}




