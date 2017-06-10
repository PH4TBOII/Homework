#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H
#include <iostream>
class MyComplex {
protected:

    double real;
    double imaginary;

public:

    //constructors
    MyComplex();
    MyComplex(double realNumber);
    MyComplex(double realNumber, double imaginaryNumber);


    double getRealPart();
    double getComplexPart();

    //operator overloads
    MyComplex operator+  (const MyComplex secondNumber);
    MyComplex operator-  (const MyComplex secondNumber);
    MyComplex operator*  (const MyComplex secondNumber);
    MyComplex operator/  (const MyComplex secondNumber);

    //augmented assignment operator overloads
    MyComplex operator+= (MyComplex secondNumber);
    MyComplex operator-= (MyComplex secondNumber);
    MyComplex operator/= (MyComplex secondNumber);
    MyComplex operator*= (MyComplex secondNumber);

    //comparison operators
    bool operator== (MyComplex secondNumber);
    bool operator!= (MyComplex secondNumber);

    //increment operators
    MyComplex operator++ (int dummy);
    MyComplex operator-- (int dummy);
    MyComplex operator++ ();
    MyComplex operator-- ();

    //unary negation operator
    MyComplex operator- ();

};
















#endif // MYCOMPLEX_H
