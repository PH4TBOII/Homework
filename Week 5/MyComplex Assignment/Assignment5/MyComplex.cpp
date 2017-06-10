#include "MyComplex.h"

//constructors
MyComplex::MyComplex()
{
    real = 0;
    imaginary = 0;
}
MyComplex::MyComplex(double realNumber)
{
    real = realNumber;
    imaginary = 0;
}
MyComplex::MyComplex(double realNumber, double imaginaryNumber)
{
    real = realNumber;
    imaginary = imaginaryNumber;
}

//return private variable functions
double MyComplex::getRealPart(){
    return this->real;
}
double MyComplex::getComplexPart() {
    return this->imaginary;
}

//operator overloads
MyComplex MyComplex::operator+ (MyComplex secondNumber) {
    MyComplex temp(real + secondNumber.real, imaginary + secondNumber.imaginary);
    return temp;
}
MyComplex MyComplex::operator- (MyComplex secondNumber) {
    MyComplex temp(real - secondNumber.real, imaginary - secondNumber.imaginary);
    return temp;
}
MyComplex MyComplex::operator* (MyComplex secondNumber) {
    double first = this->real * secondNumber.real;
    double outerInner = (this->real * secondNumber.imaginary) + (secondNumber.real * this->imaginary);
    double last = -(this->imaginary * secondNumber.imaginary);

    MyComplex temp(first + last, outerInner);
    return temp;
}
MyComplex MyComplex::operator/ (MyComplex secondNumber) {
    MyComplex temp(secondNumber);
    temp.imaginary = temp.imaginary * -1;
    MyComplex top    = this->operator*(temp);
    MyComplex bottom = secondNumber.operator*(temp);
    double newRealNumber = top.real / bottom.real;
    double newImaginaryNumber = top.imaginary / bottom.real;
    MyComplex temp4(newRealNumber,newImaginaryNumber);
    return temp4;
}

//augmented assignment operator overloads
MyComplex MyComplex::operator+=(MyComplex secondNumber) {
    real = real + secondNumber.real;
    imaginary = imaginary + secondNumber.imaginary;
    return *this;
}
MyComplex MyComplex::operator-=(MyComplex secondNumber) {
    real = real - secondNumber.real;
    imaginary = imaginary - secondNumber.imaginary;

    return *this;
}
MyComplex MyComplex::operator/=(MyComplex secondNumber) {
    MyComplex temp(this->operator/(secondNumber));
    real = temp.real;
    imaginary = temp.imaginary;
    return *this;
}
MyComplex MyComplex::operator*=(MyComplex secondNumber) {
    MyComplex temp(this->operator*(secondNumber));
    real = temp.real;
    imaginary = temp.imaginary;
    return *this;
}

//comparison operators
bool MyComplex::operator== (MyComplex secondNumber) {
    if (real == secondNumber.real && imaginary == secondNumber.imaginary)
        return true;
    else
        return false;
}
bool MyComplex::operator!= (MyComplex secondNumber) {
    if (real != secondNumber.real && imaginary != secondNumber.imaginary)
        return true;
    else
        return false;
}

//increment operators
MyComplex MyComplex::operator++ (int dummy) {
    MyComplex temp(*this);
    this->real += 1;
    return temp;
}
MyComplex MyComplex::operator-- (int dummy) {
    MyComplex temp(*this);
    this->real -= 1;
    return temp;
}
MyComplex MyComplex::operator++ () {
    this->real += 1;
    return *this;
}
MyComplex MyComplex::operator-- () {
    this->real -= 1;
    return *this;
}

//unary negation operator
MyComplex MyComplex::operator-() {
    MyComplex temp(*this);
    temp.real *= -1;
    temp.imaginary *= -1;
    return temp;
}

