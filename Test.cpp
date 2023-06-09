#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
#include <iostream>
#include <algorithm> // For __gcd
#include <typeinfo> // For typeid(...)
#include <sstream>
using namespace ariel;
using namespace std;

TEST_CASE("1-Good initialization in constructor"){
    CHECK_NOTHROW(Fraction(1,2));
    CHECK_NOTHROW(Fraction(0.25));
    Fraction frac(1,2);
    Fraction flt(0.25);
    // numinator =1, denominator=2
    CHECK((typeid(frac.getNumerator()).name()==typeid(int).name() && typeid(frac.getDenominator()).name()==typeid(int).name()));
    // numinator= 25, denominator = 100 - not in reduced form 
    CHECK((typeid(flt.getNumerator()).name()==typeid(int).name() && typeid(flt.getDenominator()).name()==typeid(int).name()));
}


TEST_CASE("2-THROW if denominator is 0 in constructor"){
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(0,0));
}

TEST_CASE("3-CHECK + operation reduced form"){
       Fraction frac1(1,2);
       Fraction frac2(3,4);
       float flt=0.4;
       Fraction frac3=frac1+frac2; // 2 normal fractions
       Fraction frac4=frac1+flt; // fraction and float
       Fraction frac5=flt+frac2; // float and fraction
       CHECK(((frac3.getNumerator()==5) && (frac3.getDenominator()==4)));
       CHECK(((frac4.getNumerator()==9) && (frac4.getDenominator()==10)));
       CHECK(((frac5.getNumerator()==23) && (frac5.getDenominator()==20)));
       CHECK(__gcd(frac3.getNumerator(),frac3.getDenominator())==1);
       CHECK(__gcd(frac4.getNumerator(),frac4.getDenominator())==1);
       CHECK(__gcd(frac5.getNumerator(),frac5.getDenominator())==1);
       


}

TEST_CASE("4-CHECK - operation reduced form"){
       Fraction frac1(1,3);
    Fraction frac2(3,4);
    float flt=0.4;
    Fraction frac3=frac1-frac2; // 2 normal fractions
    Fraction frac4=frac1-flt; // fraction and float
    Fraction frac5=flt-frac2; // float and fraction
    CHECK(((frac3.getNumerator()==-5) && (frac3.getDenominator()==12)));
    CHECK(((frac4.getNumerator()==-1) && (frac4.getDenominator()==15)));
    CHECK(((frac5.getNumerator()==-7) && (frac5.getDenominator()==20)));
    CHECK(__gcd(abs(frac3.getNumerator()), frac3.getDenominator()) == 1);
    CHECK(__gcd(abs(frac4.getNumerator()),frac4.getDenominator())==1);
    CHECK(__gcd(abs(frac5.getNumerator()),frac5.getDenominator())==1);
}

TEST_CASE("5-CHECK * operation reduced form"){
    Fraction frac1(1,3);
    Fraction frac2(3,4);
    float flt=0.4;
    Fraction frac3=frac1*frac2; // 2 normal fractions
    Fraction frac4=frac1*flt; // fraction and float
    Fraction frac5=flt*frac2; // float and fraction
    CHECK(((frac3.getNumerator()==1) && (frac3.getDenominator()==4)));
    CHECK(((frac4.getNumerator()==2) && (frac4.getDenominator()==15)));
    CHECK(((frac5.getNumerator()==3) && (frac5.getDenominator()==10)));
    CHECK(__gcd(frac3.getNumerator(),frac3.getDenominator())==1);
    CHECK(__gcd(frac4.getNumerator(),frac4.getDenominator())==1);
    CHECK(__gcd(frac5.getNumerator(),frac5.getDenominator())==1);

}

TEST_CASE("6-CHECK / operation reduced form"){
    Fraction frac1(2,4);
    Fraction frac2(3,2);
    float flt=0.01;
    Fraction frac3=frac1/frac2;
    Fraction frac4=frac1/flt;
    Fraction frac5=flt/frac2;
    
    
    CHECK((frac3.getNumerator()==1 && frac3.getDenominator()==3));
    CHECK((frac4.getNumerator()==50 && frac4.getDenominator()==1));
    CHECK((frac5.getNumerator()==1 && frac5.getDenominator()==150));
    CHECK(__gcd(frac3.getNumerator(),frac3.getDenominator())==1);
    CHECK(__gcd(frac4.getNumerator(),frac4.getDenominator())==1);
    CHECK(__gcd(frac5.getNumerator(),frac5.getDenominator())==1);
  

}


TEST_CASE("7- CHECK dividing with 0"){
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




TEST_CASE("8- CHECK not dividing with 0 - according to Order of operations "){
    CHECK_NOTHROW(Fraction(1,1)/Fraction(1,1) - Fraction(1,1));
    CHECK_NOTHROW(Fraction(1,1)- Fraction(1,1)/Fraction(1,1) );

}


TEST_CASE("9- CHECK EQUALITY when not reduced or float"){
    // fraction,fraction
    CHECK((Fraction(1,2)==Fraction(2,4)));
    CHECK((Fraction(1,2)==Fraction(0.5)));// float is converted to fraction in the constuctor.
    // float,fraction
    CHECK(0.5==Fraction(0.5)); 
    CHECK(0.3442==Fraction(344,1000));
    CHECK_FALSE(0.831==Fraction(54,65)); 
    // fraction,float
    CHECK_FALSE(Fraction(1,3)== 0.333); 
    CHECK(Fraction(333,1000)==0.333);


}


TEST_CASE("10-check < and > operaotors"){
    Fraction frac(1,3);
    float flt= 0.25; 
    Fraction arit_frac1=flt+frac;
    Fraction arit_frac2=flt-frac; // negative
    Fraction arit_frac3=frac*flt;
    Fraction arit_frac4=frac/flt;
    CHECK(Fraction(flt)<frac);
    CHECK(flt<frac);
    //with aritmentic operations
    CHECK(frac<arit_frac1);
    CHECK_FALSE(frac>arit_frac1); // since arit_frac1=1/4+1/3=7/12
    CHECK(arit_frac2<flt); // since arit_frac2=1/4-1/3=-1/12
    CHECK_FALSE(arit_frac2>flt);
    CHECK_FALSE(flt<arit_frac3); // since arit_frac3=1/3*1/4=1/12
    CHECK(flt>arit_frac3);
    CHECK_FALSE(arit_frac4<flt);// since arit_frac4=4/3
    CHECK(arit_frac4>flt);
    CHECK_FALSE(arit_frac4<frac);
    CHECK(arit_frac4>frac);

    
}



TEST_CASE("11-check >= and <= operaotors"){
    Fraction frac(1,3);
    float flt= 0.25;
    Fraction arit_frac1=flt+frac;
    Fraction arit_frac2=flt-frac; // negative
    Fraction arit_frac3=frac*flt;
    Fraction arit_frac4=frac/flt;
    CHECK(frac<=arit_frac1);
    CHECK(arit_frac1<=Fraction(7,12));
    CHECK_FALSE(frac>=arit_frac1);
    CHECK(arit_frac2<=flt); // since arit_frac2=1/4-1/3=-1/12
    CHECK(arit_frac2<=Fraction(-1,12));
    CHECK_FALSE(arit_frac2>=flt);
    CHECK_FALSE(flt<=arit_frac3); // since arit_frac3=1/3*1/4=1/12
    CHECK(flt>=arit_frac3);
    CHECK(arit_frac3>=Fraction(1,12));
    CHECK_FALSE(arit_frac4<=flt);// since arit_frac4=4/3
    CHECK(arit_frac4>=flt);
    CHECK(arit_frac4>=Fraction(4,3));
    CHECK_FALSE(arit_frac4<=frac);
    CHECK(arit_frac4>=frac);


}


TEST_CASE("12-check postfix"){
    Fraction frac1(3,9);
    // increment
    Fraction frac2= frac1++; // frac2=3/9, frac1=12/9=4/3
    CHECK((frac1.getNumerator()==4 && frac1.getDenominator()==3)); // frac1 incremented by 1
    CHECK((frac2.getNumerator()==3 && frac2.getDenominator()==9)); // frac2=frac1 before increment   
    CHECK_FALSE(frac1==frac2++); // frac1=4/3,frac2=3/9
    CHECK(frac1++==frac2); // both are 4/3 now
    CHECK_FALSE(frac1==frac2);//frac1=7/3,frac2=4/3

    // decrement
    CHECK_FALSE(frac1--==frac2);//frac1=7/3,frac2=4/3
    CHECK(frac1--==frac2);//both are 4/3 now
    CHECK_FALSE(frac1==frac2--);//frac1=1/3,frac2=4/3
    CHECK(frac1--==frac2); // both are 1/3 now
    CHECK_FALSE(frac1==frac2); //frac1=-2/3,frac2=1/3

    CHECK(__gcd(frac1.getNumerator(),frac1.getDenominator())==1);
    CHECK(__gcd(frac2.getNumerator(),frac2.getDenominator())==1);

}


TEST_CASE("13-check prefix"){
    Fraction frac1(3,9);
    // increment
    Fraction frac2= ++frac1; // frac2=12/9=4/3 , frac1=12/9=4/3
    CHECK((frac1.getNumerator()==4 && frac1.getDenominator()==3)); // frac1 incremented by 1
    CHECK((frac2.getNumerator()==4 && frac2.getDenominator()==3)); // frac2=frac1 after increment   
    CHECK_FALSE(frac1++==++frac2); //frac1=4/3, frac2=7/3
    CHECK(frac1++==frac2); // both 7/3
    CHECK(frac1==++frac2); // both 10/3

    // decrement
    --frac1;
    CHECK(frac1==frac2-1); // both 7/3
    CHECK_FALSE(frac1==frac2--); // frac1=7/3,frac2=10/3
    CHECK_FALSE(frac1==--frac2); // frac1=7/3,frac2=4/3
    CHECK(--frac1==frac2); // both 4/3

    CHECK(__gcd(frac1.getNumerator(),frac1.getDenominator())==1);
    CHECK(__gcd(frac2.getNumerator(),frac2.getDenominator())==1);
  
}



//up to 3 digits beyond decimal point
TEST_CASE("14- round float numbers - aritmetic"){
    float flt=0.0999;
    Fraction frac(1,2);
    Fraction frac_arit1=frac+flt;
    Fraction frac_arit2=flt-frac;
   // Fraction new_frac3(flt1,flt2); // forbidden! num,den have to be int
    Fraction frac_arit3=flt/frac;
    Fraction frac_arit4=frac*flt;
    

    // the outcome is 0.5999 == 0.6 == 3/5
    CHECK((frac_arit1.getNumerator()==3 && frac_arit1.getDenominator()==5));
    // the outcome is -0.4001 == -0.400 == -2/5
    CHECK((frac_arit2.getNumerator()==-2 && frac_arit2.getDenominator()==5));
    // the outcome is 0.1998 == 0.200 == 1/5
    CHECK((frac_arit3.getNumerator()==1 && frac_arit3.getDenominator()==5));
    // the outcome is 0.04995 == 0.050 == 5/100 == 1/20
    CHECK((frac_arit4.getNumerator()==1 && frac_arit4.getDenominator()==20));


}


//The << operator to print a fraction to an output stream in the format “numerator/denominator”.
//The >> operator to read a fraction from an input stream by taking two integers as input.
TEST_CASE("15- input and output streams"){
       ostringstream output;
       Fraction frac1(0.333);
       Fraction frac2;
       CHECK_NOTHROW(output << frac1);
       CHECK_EQ(output.str(),"333/1000");
       istringstream ok_input1("3 5");
       istringstream ok_input2("3 5 0 6");
       istringstream wrong_inp1("1.7/1.7");
       istringstream wrong_inp2("500");
       istringstream wrong_inp3("1,1,1,1");
       istringstream wrong_inp4("hello");
       CHECK_NOTHROW(ok_input1 >> frac1); 
       CHECK((frac1.getNumerator()==3 && frac1.getDenominator()==5)); // 333/1000 becomes 3/5
       CHECK_NOTHROW(ok_input2 >> frac1 >> frac2);
       // input should only be two integers, unless there is more than one fraction variable
       CHECK_THROWS(wrong_inp1 >> frac1 );
       CHECK_THROWS(wrong_inp2 >> frac2 );
       CHECK_THROWS(wrong_inp3 >> frac1 );
       CHECK_THROWS(wrong_inp4 >> frac2 );

}