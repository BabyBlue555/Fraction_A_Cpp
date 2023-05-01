
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;
using namespace ariel;


Fraction::Fraction(): numerator(0), denominator(1) {}

Fraction::Fraction( int _numerator,
        int _denominator):
        numerator(_numerator),denominator(_denominator){

        }

Fraction::Fraction(float flt){
    // convert from float to fraction
}



// ADD
Fraction operator+ (const Fraction& frac1, const Fraction& frac2){
    // return Fraction(c1.numinator+c2.numinator,)
    return Fraction(1,1);
 }

Fraction operator+ (const Fraction& frac1, const float& flo2){
    // return Complex(_re + other._re, _im + other._im);
    //return Fraction(c1.numinator+c)
    return Fraction(1,1);

}

Fraction operator+ (const float& flo1, const Fraction& frac2){
    return Fraction(1,1);
}

// SUBSTRACT
Fraction operator- (const Fraction& frac1, const Fraction& frac2){
    return Fraction(1,1);
}
Fraction operator- (const Fraction& frac1, const float& flo2){
        return Fraction(1,1);
}

Fraction operator- (const float& flo1, const Fraction& frac2){
    return Fraction(1,1);
}
            

// MULTIPLY
Fraction operator* (const Fraction& frac1, const Fraction& frac2){
    return Fraction(1,1);
}

Fraction operator* (const Fraction& frac1, const float& flo2){
    return Fraction(1,1);
}

Fraction operator* (const float& flo1, const Fraction& frac2){
    return Fraction(1,1);
}

// DIVIDE
Fraction operator/ (const Fraction& frac1, const Fraction& frac2){
    return Fraction(1,1);
}
Fraction operator/ (const Fraction& frac1, const float& flo2){
    return Fraction(1,1);
}
Fraction operator/ (const float& flo1, const Fraction& frac2){
    return Fraction(1,1);
}


// EQUALITY COMPARISON
bool operator==(const Fraction& frac1, const Fraction& frac2){
    return frac1.numerator==frac2.numerator && frac1.denominator==frac2.denominator;
    // add another case when one of the fractions aren't reduced
}

bool operator==(const Fraction& frac1, const float& flo2){
    return true;
}

bool operator==(const float& flo2, const Fraction& frac2){
    return true;
}


// BIGGER COMPARISON
bool operator> (const Fraction& frac1, const Fraction& frac2){
    return frac1.numerator>frac2.numerator;
    // add another case when one of the fractions aren't reduced
}
bool operator> (const Fraction& frac1, const float& flo2){
    return true;
}
bool operator> (const float& flo1, const Fraction& frac2){
    return true;
}

// SMALLER COMPARISON
bool operator< (const Fraction& frac1, const Fraction& frac2){
     return frac1.numerator<frac2.numerator;
    // add another case when one of the fractions aren't reduced
}
bool operator< (const Fraction& frac1, const float& flo2){
    return true;
}
bool operator< (const float& flo1, const Fraction& frac2){
    return true;
}

// BIGGER-EQUAL COMPARISON

bool operator>= (const Fraction& frac1, const Fraction& frac2){
    return frac1.numerator>=frac2.numerator;
    // add another case when one of the fractions aren't reduced
}
bool operator>= (const Fraction& frac1, const float& flo2){
        return true;
}
bool operator>= (const float& flo1, const Fraction& frac2){
    return true;
}

// SMALLER-EQUAL COMPARISON
bool operator<= (const Fraction& frac1, const Fraction& frac2){
     return frac1.numerator<=frac2.numerator;
    // add another case when one of the fractions aren't reduced
}
bool operator<= (const Fraction& frac1, const float& flo2){
     return true;
    // add another case when one of the fractions aren't reduced
}
bool operator<= (const float& frac1, const Fraction& flo2){
    return true;
}


//print a fraction to an output stream
std::ostream& operator<< (std::ostream& output, const Fraction& frac){
    //return cout<<"hello";
    return (output << frac.numerator << '+' << frac.denominator<< 'i');
}

//read a fraction from an input stream
std::istream& operator>> (std::istream& input , Fraction& frac){
    //  Fraction input_=Fraction(1,1);
      return input;
}

