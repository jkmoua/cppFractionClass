#include <iostream>
#include <cassert>
#include "fraction.h"
using namespace std;

/*

    Class Invariant: A Fraction object has 2 int data members: numerator, 
    which stores the numerator of the fraction, and denominator, which 
    stores the denominator of the fraction. Fraction objects will always be
    stored in the lowest terms. Improper fractions will remain improper.

*/

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}






Fraction::Fraction(int inNumberator, int inDenominator)
{
    assert(inDenominator != 0);
    numerator = inNumberator;
    denominator = inDenominator;
    simplify();
}






Fraction Fraction::addedTo(const Fraction& otherFraction) const
{
    Fraction tempFraction(numerator, denominator);

    int commonDenominator = denominator * otherFraction.denominator;
    tempFraction.numerator *= otherFraction.denominator;
    tempFraction.numerator += (otherFraction.numerator * denominator);
    tempFraction.denominator = commonDenominator;
    tempFraction.simplify();

    return tempFraction;
}






Fraction Fraction::subtract(const Fraction& otherFraction) const
{
    Fraction tempFraction(numerator, denominator);

    int commonDenominator = denominator * otherFraction.denominator;
    tempFraction.numerator *= otherFraction.denominator;
    tempFraction.numerator -= (otherFraction.numerator * denominator);
    tempFraction.denominator = commonDenominator;
    tempFraction.simplify();

    return tempFraction;
}






Fraction Fraction::multipliedBy(const Fraction& otherFraction) const
{
    Fraction tempFraction(numerator, denominator);

    tempFraction.numerator *= otherFraction.numerator;
    tempFraction.denominator *= otherFraction.denominator;
    tempFraction.simplify();

    return tempFraction;
}






Fraction Fraction::dividedBy(const Fraction& otherFraction) const
{
    Fraction tempFraction(numerator, denominator);

    tempFraction.numerator *= otherFraction.denominator;
    tempFraction.denominator *= otherFraction.numerator;
    tempFraction.simplify();

    return tempFraction;
}






bool Fraction::isEqualTo(const Fraction& otherFraction) const
{
    return (numerator * otherFraction.denominator
        == denominator * otherFraction.numerator);
}






void Fraction::print() const
{
    cout << numerator << "/" << denominator;
}






/*
This private member function reduces the calling object to the lowest terms.
*/
void Fraction::simplify()
{
    int count;

    if (numerator <= denominator) {
        count = numerator;
    } else if (denominator < numerator) {
        count = denominator;
    }

    for (; count >= 2; count--) {
        if (numerator % count == 0 && denominator % count == 0) {
            numerator /= count;
            denominator /= count;
        }
    }
}
