//Copyright (c) 2022 user1687569
#include <cstring>
#include "port.h"


Port::Port(const char * br, const char * st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}


Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}


Port & Port::operator=(const Port & p)
{
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}


Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}


Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}


void Port::Show() const
{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Kind: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}


std::ostream & operator<<(std::ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
}


VintagePort::VintagePort()
{
    nickname = new char;
    nickname[0] = '\0';
    year = 0;
}


VintagePort::VintagePort(const char * br, const char * st, int b, const char * nn, int y)
    : Port(br, st, b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}


VintagePort::VintagePort(const VintagePort & vp)
    : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}


VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    
    return *this;
}


void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl; 
}


std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
    operator<<(os, (const Port &) vp);
    os << ", " << vp.nickname << ", " << vp.year;
}


