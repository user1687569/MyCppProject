//Copyright (c) 2022 user1687569
#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
#include <cmath>

namespace VECTOR
{

class Vector
{
public:
    // Rect for rectangular, Pol for polar modes
    enum Mode {RECT, POL};
private:
    double x;
    double y;
    Mode mode;

public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void reset(double n1, double n2, Mode form = RECT);
    ~Vector();
    
    //四个报告分量值的函数是在类声明中定义的
    //因此将自动成为内联函数
    double xval() const { return x; }
    double yval() const { return y; }
    double magval() const { return sqrt(x * x + y * y); }
    double angval() const { if(x == 0.0 && y == 0.0)  { return 0.0; }   else { return atan2(y, x); }}
    void polar_mode();      // set mode to polar
    void rect_mode();       // set mode to rectangular

    Vector operator+(const Vector & b) const;
    Vector operator-(const Vector & b) const;
    Vector operator-() const;
    Vector operator*(double n) const;

    operator double() const;

    friend Vector operator*(double n, const Vector & a);
    friend std::ostream & operator<<(std::ostream & os, const Vector & v);
};

}

#endif