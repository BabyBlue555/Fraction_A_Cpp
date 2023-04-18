
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel{

};


// inline constructor
// Game::Game(Player& plr1, Player& plr2)
// : p1(plr1), p2(plr2),log(""),lastTurnStats(""),num_turns(0), num_draws(0), num_wins_p1(0), num_wins_p2(0)
// {   

    class Fraction {
        private:
            int numinator;
            int denominator;


        public:
            Fraction(int n1,int n2); // outline
            
            // add
            friend Fraction operator+ (const Fraction& c1, const Fraction& c2);
            friend Fraction operator+ (const Fraction& c1, const float& c2);
            friend Fraction operator+ (const float& c1, const Fraction& c2);

            // substract
            friend Fraction operator- (const Fraction& c1, const Fraction& c2);
            friend Fraction operator- (const Fraction& c1, const float& c2);
            friend Fraction operator- (const float& c1, const Fraction& c2);
            
           // multiply
            friend Fraction operator* (const Fraction& c1, const Fraction& c2);
            friend Fraction operator* (const Fraction& c1, const float& c2);
            friend Fraction operator* (const float& c1, const Fraction& c2);

            //divide
            friend Fraction operator/ (const Fraction& c1, const Fraction& c2);
            friend Fraction operator/ (const Fraction& c1, const float& c2);
            friend Fraction operator/ (const float& c1, const Fraction& c2);

            // comparison equality
            friend bool operator==(const Fraction& c1, const Fraction& c2);
            friend bool operator==(const Fraction& c1, const float& c2);
            friend bool operator==(const float& c1, const Fraction& c2);

            //comparison operations (>,<,>=,<=)
            friend bool operator> (const Fraction& c1, const Fraction& c2);
            friend bool operator> (const Fraction& c1, const float& c2);
            friend bool operator> (const float& c1, const Fraction& c2);

            friend bool operator< (const Fraction& c1, const Fraction& c2);
            friend bool operator< (const Fraction& c1, const float& c2);
            friend bool operator< (const float& c1, const Fraction& c2);

            friend bool operator>= (const Fraction& c1, const Fraction& c2);
            friend bool operator>=(const Fraction& c1, const float& c2);
            friend bool operator>= (const float& c1, const Fraction& c2);

            friend bool operator<= (const Fraction& c1, const Fraction& c2);
            friend bool operator<= (const Fraction& c1, const float& c2);
            friend bool operator<= (const float& c1, const Fraction& c2);



            
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

            friend std::ostream& operator<< (std::ostream& output, const Fraction& c);




            //The >> operator to read a fraction from an input stream 
            //by taking two integers as input.
            friend std::istream& operator>> (std::istream& input , Fraction& c);



    }; // end of class Fraction

    #endif

    