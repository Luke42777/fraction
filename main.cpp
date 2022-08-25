/*
 * main.cpp
 *
 *  Created on: 22 Aug 2022
 *      Author: Lukasz
 */

#include <iostream>
#include "fraction.h"
using namespace std;


int main(){
Fraction frac1(2,3);
Fraction frac2(2,3);
Fraction frac3;
frac3 = frac1.Divide(frac2);

cout << frac3;
}




