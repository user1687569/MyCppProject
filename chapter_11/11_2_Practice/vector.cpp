//Copyright (c) 2022 user1687569
#include <iostream>
#include <cmath>
#include "vector.h"


namespace VECTOR
{
const double Radius_To_Degree = 45.0 / atan(1.0);

Vector::Vector()
{
    // x = y = mag = ang = 0.0;
    x = y = 0.0;
    mode = RECT;
}


Vector::Vector(double n1, double n2, Mode form)
{
    mode = form;
    if(form == RECT)
    {
        x = n1;
        y = n2;
    }
    else if(form == POL)
    {
        x = n1 * cos(n2 / Radius_To_Degree);
        y = n1 * sin(n2 / Radius_To_Degree);
    }
    else
    {
        std::cout << "Incorrect 3rd argument to Vector() -- ";
        std::cout << "vector set to 0" << std::endl;
        x = y = 0.0;
        mode = RECT;
    }
}


void Vector::reset(double n1, double n2, Mode form)
{
    mode = form;
    if(form == RECT)
    {
        x = n1; 
        y = n2;
    }
    else if(form == POL)
    {
        x = n1 * cos(n2 / Radius_To_Degree);
        y = n1 * sin(n2 / Radius_To_Degree);
    }
    else
    {
        std::cout << "Incorrect 3rd argument to Vector() -- ";
        std::cout << "vector set to 0" << std::endl;
        x = y = 0.0;
        mode = RECT;
    }
}

Vector::~Vector()
{
}


void Vector::polar_mode()
{
    mode = POL;
}


void Vector::rect_mode()
{
    mode = RECT;
}


Vector Vector::operator+(const Vector & b) const
{
    return Vector(x + b.x, y + b.y);
}


Vector Vector::operator-(const Vector & b) const
{
    return Vector(x - b.x, y - b.y);
}


std::ostream & operator<<(std::ostream & os, const Vector & v)
{
    if(v.mode == Vector::RECT)
        os << "(x, y) = (" << v.x << ", " << v.y << ")" << std::endl;
    else if(v.mode == Vector::POL)
        os << "(m, a) = (" << v.magval() << ", " << v.angval() * Radius_To_Degree << ")" << std::endl;
    else
        os << "Vector object mode is invalid";

    return os; 
}


Vector::operator double() const
{
    return magval();
}

}

