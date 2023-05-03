
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
            if(_denominator==0){
                throw invalid_argument("denominator is 0");
            }
            if(typeid(_numerator).name()!=typeid(int).name() || typeid(_denominator).name()!=typeid(int).name()){
                __throw_bad_typeid(); 
                // or: throw ("numerator and denominator have to be from type int)
            }

            if(_numerator<0 && _denominator<0 || _denominator<0){
                numerator *= -1;
                denominator *= -1;
            }


        }

Fraction::Fraction(float flt){
    // convert from float to fraction
    int power=1;
    float cpy=flt;
   
    while(std::fmod(cpy, 1.0)  && power < 1000){ // as long as the decimal value isn't 0 
    // the limitation on power is because we want to have up to 3 digits beyond the desimal point 
    //&& number != (int)number
        power *=10;
        cpy*=10;
    }
    this->numerator=cpy;
    this->denominator=power;

    //reduced(numerator,denominator);

}


// int Fraction::lcm(int denom1, int denom2 ){
//     int _lcm=(denom1 / __gcd(denom1, denom2)) * denom2;
//     return _lcm ;
// }

void Fraction::reduced(int& numerator, int& denominator){
int gcd=__gcd(abs(numerator), abs(denominator));
                numerator /= gcd;
                denominator /=gcd;
}



// ADD
const Fraction Fraction::operator+ (const Fraction& other) const{
    // return Fraction(c1.numinator+c2.numinator,)
    // int _lcm=lcm(frac1.getDenom(), frac2.getDenom());
    // int new_numr=frac1.getNuminator()*(_lcm/frac1.getDenom())+frac2.getNuminator()*(_lcm/frac2.getDenom());
    // int new_denom=_lcm;
    
    return Fraction(1,1);
    //reduced(new_numr,new_denom);
 }

const Fraction Fraction::operator+ (const float& _float) const{
    // return Complex(_re + other._re, _im + other._im);
    //return Fraction(c1.numinator+c)
    
    return Fraction(1,1);


}

const Fraction operator+ (const float& flo1, const Fraction& frac2){
    return Fraction(1,1);
}

// SUBSTRACT
const Fraction Fraction::operator- (const Fraction& other) const{
    return Fraction(1,1);
}
const Fraction Fraction::operator- ( const float& _float) const{
        return Fraction(1,1);
}

const Fraction operator- (const float& flo1, const Fraction& frac2){
    return Fraction(1,1);
}
            

// MULTIPLY
const Fraction Fraction::operator* (const Fraction& other) const{
    return Fraction(1,1);
}

const Fraction Fraction::operator- (const float& _float) const{
    return Fraction(1,1);
}

const Fraction operator* (const float& flo1, const Fraction& frac2){
    return Fraction(1,1);
}

// DIVIDE
const Fraction Fraction::operator/ (const Fraction& other) const{
    return Fraction(1,1);
}
const Fraction Fraction::operator/ (const float& _float) const{
    return Fraction(1,1);
}
const Fraction operator/ (const float& flo1, const Fraction& frac2){
    return Fraction(1,1);
}


// EQUALITY COMPARISON
bool Fraction::operator==(const Fraction& other){
    return this->numerator==other.numerator && this->denominator==other.denominator;
    // add another case when one of the fractions aren't reduced
}

bool Fraction::operator==(const float& float_){
    return true;
}

bool operator==(const float& flo2, const Fraction& frac2){
    return true;
}


// BIGGER COMPARISON
bool Fraction::operator> (const Fraction& other){
    return numerator>other.numerator;
    // add another case when one of the fractions aren't reduced
}
bool Fraction::operator> ( const float& float_){
    return true;
}
bool operator> (const float& flo1, const Fraction& frac2){
    return true;
}

// SMALLER COMPARISON
bool Fraction::operator< (const Fraction& other){
     return numerator<other.numerator;
    // add another case when one of the fractions aren't reduced
}
bool Fraction::operator< (const float& float_){
    return true;
}
bool operator< (const float& flo1, const Fraction& frac2){
    return true;
}

// BIGGER-EQUAL COMPARISON

bool Fraction::operator>= (const Fraction& other){
    return numerator>=other.numerator;
    // add another case when one of the fractions aren't reduced
}
bool Fraction::operator>= ( const float& float_){
        return true;
}
bool operator>= (const float& flo1, const Fraction& frac2){
    return true;
}

// SMALLER-EQUAL COMPARISON
bool  Fraction::operator<= (const Fraction& other){
     return numerator<=other.numerator;
    // add another case when one of the fractions aren't reduced
}
bool  Fraction::operator<= (const float& float_){
     return true;
    // add another case when one of the fractions aren't reduced
}
bool operator<= (const float& frac1, const Fraction& flo2){
    return true;
}


//print a fraction to an output stream
std::ostream& operator<< (std::ostream& output, const Fraction& frac){
    output << frac.numerator << '/' << frac.denominator;
    return output;
}


 istream& operator>>(istream& is, Fraction& fraction) {
        int numerator, denominator;
        char slash;

        is >> numerator >> slash >> denominator;

        if (slash != '/')
            throw invalid_argument("Invalid input");

        fraction = Fraction(numerator, denominator);

        return is;
    }