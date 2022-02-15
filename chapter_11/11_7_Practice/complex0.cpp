//Copyright (c) 2022 user1687569
#include <iostream>
#include "complex0.h"


Complex::Complex()
{
    real = 0.0;
    imaginary = 0.0;
}


Complex::Complex(double x, double y)
{
    real = x;
    imaginary = y;
}


Complex::~Complex()
{
}


Complex Complex::operator+(const Complex & c) const
{
    Complex result;
    result.real = real + c.real;
    result.imaginary = imaginary + c.imaginary;
    return result;
}


Complex Complex::operator-(const Complex & c) const
{
    Complex result;
    result.real = real - c.real;
    result.imaginary = imaginary - c.imaginary;
    return result;
}


Complex Complex::operator*(const Complex & c) const
{
    Complex result;
    result.real = real * c.real - imaginary * c.imaginary;
    result.imaginary = real * c.imaginary + imaginary * c.real;
    return result;
}


Complex Complex::operator*(double x) const
{
    Complex result;
    result.real = real * x;
    result.imaginary = imaginary * x;
    return result;
}


Complex Complex::operator~() const
{
    Complex result;
    result.real = real;
    result.imaginary = -imaginary;
    return result;
}


Complex operator*(double x, const Complex & c)
{
    Complex result;
    result.real = x * c.real;
    result.imaginary = x * c.imaginary;
    return result;
}


std::ostream & operator<<(std::ostream & os, const Complex & c)
{
    os << "(" << c.real << ", " << c.imaginary << "i)";
}


std::istream & operator>>(std::istream & is, Complex & c)
{
    std::cout << "real: ";
    is >> c.real;
    std::cout << "imaginary: ";
    is >> c.imaginary;
    return is;
}



