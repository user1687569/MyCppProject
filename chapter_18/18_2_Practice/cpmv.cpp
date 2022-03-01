//Copyright (c) 2022 user1687569
#include <iostream>
#include "cpmv.h"

Cpmv::Cpmv()
{
    pi = new Cpmv::Info;
    pi->qcode = "Blockchain Lee.";
    pi->zcode = "Great";
}


Cpmv::Cpmv(std::string q, std::string z)
{
    pi = new Cpmv::Info;
    pi->qcode = q;
    pi->zcode = z;
}


Cpmv::Cpmv(const Cpmv & cp)
{
    pi = new Cpmv::Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}


Cpmv::Cpmv(Cpmv && mv)
{
    pi = new Cpmv::Info;
    pi = mv.pi;
    mv.pi = nullptr;
}


Cpmv::~Cpmv()
{
    delete pi;
}


Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    if(this == &cp)
        return *this;
    delete pi;

    pi = new Cpmv::Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;

    return *this;
}


Cpmv & Cpmv::operator=(const Cpmv && cp)
{
    if(this == &cp)
        return *this;
    delete pi;

    pi = new Cpmv::Info;
    pi = cp.pi;
    // cp.pi = nullptr;

    return *this;
}


Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    Cpmv temp;
    temp.pi = new Cpmv::Info;
    temp.pi->qcode = pi->qcode + obj.pi->qcode;
    temp.pi->zcode = pi->zcode + obj.pi->qcode;

    return temp;
}


void Cpmv::Display() const
{
    std::cout << "qcode: " << pi->qcode << ", zcode: " << pi->zcode << std::endl;
}


