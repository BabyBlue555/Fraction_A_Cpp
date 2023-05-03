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

void Fraction::reduced(int& numerator, int& denominator) const{
    int gcd=__gcd(abs(numerator), abs(denominator));
    numerator /= gcd;
    denominator /=gcd;
}



// ADD
const Fraction Fraction::operator+ (const Fraction& other) const{
    int new_numr= (this->numerator*other.denominator)+(other.numerator*this->denominator);
    int new_denom=this->denominator*other.denominator;
    reduced(new_numr,new_denom);
    return Fraction(new_numr,new_denom);
 }

const Fraction Fraction::operator+ (const float& _float) const{
    // use in the above + function
    // this is a pointer, *this is the value i.e the fraction
    return *this+Fraction(_float);
    
    //return Fraction(1,1);


}

const Fraction operator+ (const float& flo1, const Fraction& frac2){
    return Fraction(flo1)+frac2;
}

// SUBSTRACT
const Fraction Fraction::operator- (const Fraction& other) const{
    int new_numr= (this->numerator*other.denominator)-(other.numerator*this->denominator);
    int new_denom=this->denominator*other.denominator;
    reduced(new_numr,new_denom);
    return Fraction(new_numr,new_denom);
}
const Fraction Fraction::operator- ( const float& _float) const{
    return *this-Fraction(_float);
}

const Fraction operator- (const float& flo1, const Fraction& frac2){
    return Fraction(flo1)-frac2;
}
            

// MULTIPLY
const Fraction Fraction::operator* (const Fraction& other) const{
    int new_numr= this->numerator*other.numerator;
    int new_denom=this->denominator*other.denominator;
    reduced(new_numr,new_denom);
    return Fraction(new_numr,new_denom);
}

const Fraction Fraction::operator* (const float& _float) const{
    return (*this)*Fraction(_float);
}

const Fraction operator* (const float& flo1, const Fraction& frac2){
    return Fraction(flo1)*frac2;;
}

// DIVIDE
const Fraction Fraction::operator/ (const Fraction& other) const{
    int new_numr= (this->numerator*other.denominator);
    int new_denom=other.numerator*this->denominator;
    reduced(new_numr,new_denom);
    return Fraction(new_numr,new_denom);
}
const Fraction Fraction::operator/ (const float& _float) const{
    return *this/Fraction(_float);
}
const Fraction operator/ (const float& flo1, const Fraction& frac2){
    return Fraction(flo1)/frac2;
}


// EQUALITY COMPARISON
bool Fraction::operator==(const Fraction& other) const{
    return this->numerator==other.numerator && this->denominator==other.denominator;
    // add another case when one of the fractions aren't reduced
}

bool Fraction::operator==(const float& float_) const{
    return true;
}

bool operator==(const float& flo2, const Fraction& frac2) {
    return true;
}


// BIGGER COMPARISON
bool Fraction::operator> (const Fraction& other) const{
    return numerator>other.numerator;
    // add another case when one of the fractions aren't reduced
}
bool Fraction::operator> ( const float& float_) const{
    return true;
}
bool operator> (const float& flo1, const Fraction& frac2){
    return true;
}

// SMALLER COMPARISON
bool Fraction::operator< (const Fraction& other) const{
     return numerator<other.numerator;
    // add another case when one of the fractions aren't reduced
}
bool Fraction::operator< (const float& float_) const{
    return true;
}
bool operator< (const float& flo1, const Fraction& frac2){
    return true;
}

// BIGGER-EQUAL COMPARISON

bool Fraction::operator>= (const Fraction& other) const{
    return numerator>=other.numerator;
    // add another case when one of the fractions aren't reduced
}
bool Fraction::operator>= ( const float& float_) const{
        return true;
}
bool operator>= (const float& flo1, const Fraction& frac2){
    return true;
}

// SMALLER-EQUAL COMPARISON
bool Fraction::operator<= (const Fraction& other) const{
     return numerator<=other.numerator;
    // add another case when one of the fractions aren't reduced
}
bool Fraction::operator<= (const float& float_) const{
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


 istream& operator>>(istream& input, Fraction& fraction) {
        int numerator, denominator;
        char slash;

        input >> numerator >> slash >> denominator;

        if (slash != '/')
            throw invalid_argument("Invalid input");

        fraction = Fraction(numerator, denominator);

        return input;
    }