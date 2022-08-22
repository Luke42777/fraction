/*
 * fraction.cpp
 *
 *  Created on: 22 Aug 2022
 *      Author: Lukasz
 */
#include <iostream>
#include "fraction.h"


Fraction::Fraction(int nom,int denom){
	std::cout << "Constructed";
	mNominator = nom;
	mDenominator = denom;
}

Fraction::Fraction():Fraction(0,1){}




