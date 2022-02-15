//Copyright (c) 2022 user1687569
#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>

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
    double mag;     //length of vector 
    double ang;     //direction of vector, radius: [-pi] ~ [+pi]
    Mode mode;
    void set_mag();
    void set_ang();
    void set_x();
    void set_y();

public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void reset(double n1, double n2, Mode form = RECT);
    ~Vector();
    
    //四个报告分量值的函数是在类声明中定义的
    //因此将自动成为内联函数
    double xval() const { return x; }
    double yval() const { return y; }
    double magval() const { return mag; }
    double angval() const { return ang; }
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