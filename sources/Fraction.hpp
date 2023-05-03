
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel{

};


    class Fraction {
        private:
            int numerator;
            int denominator;


        public:

            // outline constructors
            Fraction();
            Fraction( int _numerator,int _denominator);
            Fraction(float flt);

            int getNuminator() const{
                return numerator;
            }

            int getDenom() const{
                return denominator;
            }

            // returns the Least common multiple
            //int lcm(int denom1, int denom2 );
            // returns the greatest common divisor of the fractions
            // int gcd(int num,int denom);
            // returns the Least common multiple
            void reduced(int& numerator, int& denominator);

            // FRIEND FUNCTION - usually , functions that their first argument is not
            // from the type of the class.
            // functions like operator+ that takes as arguments 2 fractions shouldn't be 
            // in contrast, functions of assignment such as += have to be friend functions 
            // since they return a reference because the value of the object has changed.

            // add
            const Fraction operator+ (const Fraction& other) const;
            const Fraction operator+ (const float& num) const;
            //      const Fraction operator+(const float& num) const;
            friend const Fraction operator+ (const float& flo1, const Fraction& frac2);

            // substract
            const Fraction operator- (const Fraction& other) const;
            const Fraction operator- (const float& _float) const;
            friend const Fraction operator- (const float& flo1, const Fraction& frac2);
            
           // multiply
            const Fraction operator* (const Fraction& other) const;
            const Fraction operator* (const float& _float) const;
            friend const Fraction operator* (const float& flo1, const Fraction& frac2);

            //divide
            const Fraction operator/ (const Fraction& other) const;
            const Fraction operator/ (const float& _float) const;
            friend const Fraction operator/ (const float& flo1, const Fraction& frac2);

            // comparison equality
            bool operator==(const Fraction& other);
            bool operator==(const float& _float);
            friend bool operator==(const float& flo2, const Fraction& frac2);

            //comparison operations (>,<,>=,<=)
            bool operator> (const Fraction& other);
            bool operator> (const float& float_);
            friend bool operator> (const float& flo2, const Fraction& frac2);

            bool operator< (const Fraction& other);
            bool operator< (const float& float_);
            friend bool operator< (const float& flo2, const Fraction& frac2);

            bool operator>= (const Fraction& other);
            bool operator>=(const float& float_);
            friend bool operator>= (const float& flo2, const Fraction& frac2);

            bool operator<= (const Fraction& other);
            bool operator<= ( const float& float_);
            friend bool operator<= (const float& flo2, const Fraction& frac2);



            
            // prefix increment: returns the fraction after increment
            Fraction& operator++() {
                numerator++;
                return *this;
            }

            // postfix increment: returns copy of the fraction - its value before increment
            Fraction operator++(int dummy_flag_for_postfix_increment) {
                Fraction copy = *this;
                numerator++;
                return copy;
            }

            // prefix decrease
             Fraction& operator--() {
                numerator--;
                return *this;
            }


            // postfix decrease
             Fraction operator--(int dummy_flag_for_postfix_increment) {
                Fraction copy = *this;
                numerator--;
                return copy;
            }



            //----------------------------------
            // friend global IO operators
            //----------------------------------

            //The << operator to print a fraction to an output stream 
            //in the format “numerator/denominator”.

            friend std::ostream& operator<< (std::ostream& output, const Fraction& frac);




            //The >> operator to read a fraction from an input stream 
            //by taking two integers as input.
            friend std::istream& operator>> (std::istream& is , Fraction& fraction);





    }; // end of class Fraction

//}; // end-namespace-ariel

    #endif

    