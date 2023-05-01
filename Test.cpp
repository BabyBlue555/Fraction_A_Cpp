#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
#include <iostream>
#include <algorithm> // For __gcd; taken from the internet
#include <typeinfo> // For typeid(...)
#include <sstream>
using namespace ariel;
using namespace std;

TEST_CASE("Good initialization in constructor"){
    Fraction a(1,2);
    CHECK_NOTHROW(Fraction(1,2));
    CHECK((typeid(a.getNuminator()).name()==typeid(int).name() && typeid(a.getDenom()).name()==typeid(int).name()));
    CHECK_NOTHROW(Fraction(0.567));
    
}


TEST_CASE("THROW if denominator is 0 in constructor"){
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(0,0));
}

TEST_CASE("CHECK + operation reduced form"){
       Fraction frac1(1,2);
       Fraction frac2(3,4);
       float flt=0.4;
       Fraction frac3=frac1+frac2; // 2 normal fractions
       Fraction frac4=frac1+flt; // fraction and float
       Fraction frac5=flt+frac2; // float and fraction
       CHECK(((frac3.getNuminator()==5) && (frac3.getDenom()==4)));
       CHECK(((frac4.getNuminator()==9) && (frac4.getDenom()==10)));
       CHECK(((frac5.getNuminator()==23) && (frac4.getDenom()==20)));

}

TEST_CASE("CHECK - operation reduced form"){
    Fraction frac1(1,3);
    Fraction frac2(3,4);
    float flt=0.4;
    Fraction frac3=frac1-frac2; // 2 normal fractions
    Fraction frac4=frac1-flt; // fraction and float
    Fraction frac5=flt-frac2; // float and fraction
    CHECK(((frac3.getNuminator()==-5) && (frac3.getDenom()==12)));
    CHECK(((frac4.getNuminator()==-1) && (frac4.getDenom()==15)));
    CHECK(((frac5.getNuminator()==-7) && (frac4.getDenom()==20)));

}

TEST_CASE("CHECK * operation reduced form"){
    Fraction frac1(1,3);
    Fraction frac2(3,4);
    float flt=0.4;
    Fraction frac3=frac1*frac2; // 2 normal fractions
    Fraction frac4=frac1*flt; // fraction and float
    Fraction frac5=flt*frac2; // float and fraction
    CHECK(((frac3.getNuminator()==1) && (frac3.getDenom()==4)));
    CHECK(((frac4.getNuminator()==2) && (frac4.getDenom()==15)));
    CHECK(((frac5.getNuminator()==3) && (frac4.getDenom()==10)));

}

TEST_CASE("CHECK / operation reduced form"){
    Fraction frac1(2,4);
    Fraction frac2(3,2);
    float flt=0.01;
    Fraction frac3=frac1/frac2;
    Fraction frac4=frac1/flt;
    Fraction frac5=flt/frac2;
    
    
    CHECK((frac3.getNuminator()==1 && frac3.getDenom()==3));
    CHECK((frac4.getNuminator()==50 && frac4.getDenom()==1));
    CHECK((frac5.getNuminator()==1 && frac5.getDenom()==150));
    CHECK(frac3== 4/12); // both equal to 1/3
    CHECK(frac4== 100/2); // both equal to 50/1
    CHECK(frac5== 2/300); // both equal to 1/150
    CHECK(Fraction(flt)== 1/100); // float is converted to fraction in the constuctor. 
    

}


// TEST_CASE("CHECK EQUALITY == THROWS"){
//     Fraction frac1(1,2);
//     Fraction frac2(12,36);
//     float flt=0.567;
// }


TEST_CASE("CHECK EQUALITY when not reduced or float"){
    CHECK((Fraction(1,2)==Fraction(2,4)));
    CHECK((Fraction(12,36)==Fraction(1,3)));
    CHECK((Fraction(24,12)==2/1)); // ????
    CHECK((Fraction(1,2)==Fraction(0.5)));
    
    // check this again
    CHECK_FALSE(Fraction(1,3)==0.333);
    CHECK(0.5==Fraction(0.5)); // float,fraction
    CHECK(Fraction(333,1000)==0.333);// fraction,float

}

TEST_CASE("CHECK dividing with 0"){
    Fraction frac1(1,3);
    float flt=0.400;
    Fraction frac2= frac1/flt; 
    Fraction frac3=flt/frac2;
    //  denominator is 0
    CHECK_THROWS(frac1/0);
    CHECK_THROWS(Fraction(flt)/0);
    CHECK_THROWS(frac2/0);
    CHECK_THROWS(frac3/0);
    // denominator is an illigal expression==0
    CHECK_THROWS((frac1/Fraction(1,0))); 
    CHECK_THROWS((flt/(Fraction(1,1)-Fraction(1,1))));
}

//should compile
TEST_CASE("CHECK not dividing with 0 - according to Order of operations "){
    CHECK_NOTHROW(Fraction(1,1)/Fraction(1,1) - Fraction(1,1));
    CHECK_NOTHROW(Fraction(1,1)- Fraction(1,1)/Fraction(1,1) );

}



//up to 3 digits beyond decimal point
TEST_CASE("round float numbers"){
    float flt1=0.25;
    float flt2=0.0999;
    Fraction frac(1,2);
    Fraction new_frac1=frac+flt2;
    Fraction new_frac2=flt2-frac;
    Fraction new_frac3(flt1,flt2);

    

    // the outcome is 1.499 == 1.500 == 3/2
    CHECK((new_frac2.getNuminator()==3 && new_frac2.getDenom()==2));
    // the outcome is -0.4001 == -0.400 == -2/5
    CHECK((new_frac2.getNuminator()==-2 && new_frac2.getDenom()==5));

}


// which tests can i do for the << and >>