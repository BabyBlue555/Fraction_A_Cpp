
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

namespace ariel{

};


    class Fraction {
        private:
            int numinator;
            int denominator;


        public:

            Fraction( int _numinator,int _denominator);
            Fraction(float flt);
            //Fraction(int,int ); // outline
            int getNuminator() const{
                return numinator;
            }

            int getDenom() const{
                return denominator;
            }

            
            
            // add
            friend Fraction operator+ (const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator+ (const Fraction& frac1, const float& flo2);
            friend Fraction operator+ (const float& flo1, const Fraction& frac2);

            // substract
            friend Fraction operator- (const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator- (const Fraction& frac1, const float& flo2);
            friend Fraction operator- (const float& flo1, const Fraction& frac2);
            
           // multiply
            friend Fraction operator* (const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator* (const Fraction& frac1, const float& flo2);
            friend Fraction operator* (const float& flo1, const Fraction& frac2);

            //divide
            friend Fraction operator/ (const Fraction& frac1, const Fraction& frac2);
            friend Fraction operator/ (const Fraction& frac1, const float& flo2);
            friend Fraction operator/ (const float& flo1, const Fraction& frac2);

            // comparison equality
            friend bool operator==(const Fraction& frac1, const Fraction& frac2);
            friend bool operator==(const Fraction& frac1, const float& flo2);
            friend bool operator==(const float& flo2, const Fraction& frac2);

            //comparison operations (>,<,>=,<=)
            friend bool operator> (const Fraction& frac1, const Fraction& frac2);
            friend bool operator> (const Fraction& frac1, const float& flo2);
            friend bool operator> (const float& flo2, const Fraction& frac2);

            friend bool operator< (const Fraction& frac1, const Fraction& frac2);
            friend bool operator< (const Fraction& frac1, const float& flo2);
            friend bool operator< (const float& flo2, const Fraction& frac2);

            friend bool operator>= (const Fraction& frac1, const Fraction& frac2);
            friend bool operator>=(const Fraction& frac1, const float& flo2);
            friend bool operator>= (const float& flo2, const Fraction& frac2);

            friend bool operator<= (const Fraction& frac1, const Fraction& frac2);
            friend bool operator<= (const Fraction& frac1, const float& flo2);
            friend bool operator<= (const float& flo2, const Fraction& frac2);



            
            // prefix increment: returns the fraction after increment
            Fraction& operator++() {
                numinator++;
                return *this;
            }

            // postfix increment: returns copy of the fraction - its value before increment
            Fraction operator++(int dummy_flag_for_postfix_increment) {
                Fraction copy = *this;
                numinator++;
                return copy;
            }

            // prefix decrease
             Fraction& operator--() {
                numinator--;
                return *this;
            }


            // postfix decrease
             Fraction operator--(int dummy_flag_for_postfix_increment) {
                Fraction copy = *this;
                numinator--;
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
            friend std::istream& operator>> (std::istream& input , Fraction& frac);



    }; // end of class Fraction

//}; // end-namespace-ariel

    #endif

    