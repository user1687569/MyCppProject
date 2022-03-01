//Copyright (c) 2022 user1687569
#ifndef _CPMV_H_
#define _CPMV_H_
#include <iostream>
#include <string>

class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };

private:
    Info *pi;
public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv & cp);
    Cpmv(Cpmv && mv);
    ~Cpmv();
    Cpmv & operator=(const Cpmv & cp);
    Cpmv & operator=(const Cpmv && cp);
    Cpmv operator+(const Cpmv & obj) const;
    void Display() const;
};


#endif