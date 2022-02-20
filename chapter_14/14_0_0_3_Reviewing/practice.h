//Copyright (c) 2022 user1687569
#ifndef _PRACTICE_H_
#define _PRACTICE_H_
#include <iostream>
#include <string>
#include <cstring>

class Frabjous
{
private:
    char fab[20];

public:
    Frabjous(const char * s = "C++");
    virtual void tell() { std::cout << fab << std::endl; }
};


class Gloam : private Frabjous
{
private:
    int glip;

public:
    Gloam(int g = 0, const char * s = "C++");
    Gloam(int g, const Frabjous & f);
    void tell();
};


#endif