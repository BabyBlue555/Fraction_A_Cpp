
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;
using namespace ariel;


Fraction::Fraction(int n1,int n2){

}


// ADD
Fraction operator+ (const Fraction& c1, const Fraction& c2){

 }

Fraction operator+ (const Fraction& c1, const float& c2){

}

Fraction operator+ (const float& c1, const Fraction& c2){

}

// SUBSTRACT
Fraction operator- (const Fraction& c1, const Fraction& c2){

}
Fraction operator- (const Fraction& c1, const float& c2){
    
}

Fraction operator- (const float& c1, const Fraction& c2){

}
            

// MULTIPLY
Fraction operator* (const Fraction& c1, const Fraction& c2){

}

Fraction operator* (const Fraction& c1, const float& c2){

}

Fraction operator* (const float& c1, const Fraction& c2){

}

// DIVIDE
Fraction operator/ (const Fraction& c1, const Fraction& c2){

}
Fraction operator/ (const Fraction& c1, const float& c2){

}
Fraction operator/ (const float& c1, const Fraction& c2){

}


// EQUALITY COMPARISON
bool operator==(const Fraction& c1, const Fraction& c2){

}

bool operator==(const Fraction& c1, const float& c2){

}

bool operator==(const float& c1, const Fraction& c2){

}


// BIGGER COMPARISON
bool operator> (const Fraction& c1, const Fraction& c2){

}
bool operator> (const Fraction& c1, const float& c2){

}
bool operator> (const float& c1, const Fraction& c2){

}

// SMALLER COMPARISON
bool operator< (const Fraction& c1, const Fraction& c2){

}
bool operator< (const Fraction& c1, const float& c2){

}
bool operator< (const float& c1, const Fraction& c2){

}

// BIGGER-EQUAL COMPARISON

bool operator>= (const Fraction& c1, const Fraction& c2){

}
bool operator>= (const Fraction& c1, const float& c2){

}
bool operator>= (const float& c1, const Fraction& c2){

}

// SMALLER-EQUAL COMPARISON
bool operator<= (const Fraction& c1, const Fraction& c2){

}
bool operator<= (const Fraction& c1, const float& c2){

}
bool operator<= (const float& c1, const Fraction& c2){

}


//print a fraction to an output stream
std::ostream& operator<< (std::ostream& output, const Fraction& c){

}

//read a fraction from an input stream
std::istream& operator>> (std::istream& input , Fraction& c){

}

