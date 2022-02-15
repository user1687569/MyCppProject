//Copyright (c) 2022 user1687569
#ifndef _COMPLEX0_H_
#define _COMPLEX0_H_


class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double x, double y);
    ~Complex();

    Complex operator+(const Complex & c) const;
    Complex operator-(const Complex & c) const;
    Complex operator*(const Complex & c) const;
    Complex operator*(double x) const;
    Complex operator~() const;

    // friend Complex operator*(double x, const Complex & c)
    // { return c * x; }
    friend Complex operator*(double x, const Complex & c);
    friend std::ostream & operator<<(std::ostream & os, const Complex & c);
    friend std::istream & operator>>(std::istream & is, Complex & c);
};

#endif

