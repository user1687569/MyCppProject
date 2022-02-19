//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "cow.h"


Cow::Cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0.0;
}


Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name, nm);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}


Cow::Cow(const Cow & c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    weight = c.weight;
}


Cow::~Cow()
{
    delete [] hobby;
}


Cow & Cow::operator=(const Cow & c)
{
    if(this == &c)
        return *this;
    //释放str指向的内存，并为新字符串分配足够的内存
    strcpy(name, c.name);

    delete [] hobby;
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}


void Cow::ShowCow() const
{
    std::cout << "Cow Information: " << std::endl;
    std::cout << "  Name: " << name << std::endl;
    std::cout << " Hobby: " << hobby << std::endl;
    std::cout << "Weight: " << weight << std::endl;
}

