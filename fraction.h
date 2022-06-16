#ifndef FRACTION_H
#define FRACTION_H

/*
 
The Fraction class can be used to create objects that store a fraction, including
the numerator and denominator. The following functions are available:

Fraction();
    post: The calling object has been created and initialized to 0/1

Fraction(int inNumberator, int inDenominator);
    pre:  The value of inDenominator cannot be 0.
    post: The calling object has been created and initialized so that the numerator
          is inNumerator and the denominator is inDenominator.

Fraction addedTo(const Fraction& otherFraction) const;
    post: Returns the Fraction determined by adding otherFraction to the calling 
          object.

Fraction subtract(const Fraction& otherFraction) const;
    post: Returns the Fraction determined by subtracting otherFraction from the 
          calling object.

Fraction multipliedBy(const Fraction& otherFraction) const;
    post: Returns the Fraction determined by multiplying the calling object by
          otherFraction.

Fraction dividedBy(const Fraction& otherFraction) const;
    post: Returns the Fraction determined by dividing the calling object by 
          otherFraction.

bool isEqualTo(const Fraction& otherFraction) const;
    post: Returns true if the calling object is equivalent to otherFraction.
          Otherwise, returns false.

void print() const;
    post: The calling object has been printed to the console window in the format
          "numerator/denominator."

*/

class Fraction {
public:
    Fraction();
    Fraction(int inNumberator, int inDenominator);
    Fraction addedTo(const Fraction& otherFraction) const;
    Fraction subtract(const Fraction& otherFraction) const;
    Fraction multipliedBy(const Fraction& otherFraction) const;
    Fraction dividedBy(const Fraction& otherFraction) const;
    bool isEqualTo(const Fraction& otherFraction) const;
    void print() const;
private:
    void simplify();
    int numerator;
    int denominator;
};

#endif