//Copyright (c) 2022 user1687569
#ifndef _PLACENEW_H_
#define _PLACENEW_H_
#include <iostream>
#include <string>
#include <new>

const int BUF = 512;


class PlaceNew
{
private:
    std::string words;
    int number;

public:
    PlaceNew(const std::string & s = "Just Testing", int n = 0);
    ~PlaceNew();
    void Show() const;

};

#endif