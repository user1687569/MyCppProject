//Copyright (c) 2022 user1687569
#include <iostream>
#include "placenew.h"


PlaceNew::PlaceNew(const std::string & s, int n)
{
    words = s;
    number = n;
    std::cout << words << " constructed." << std::endl;
}


PlaceNew::~PlaceNew()
{
    std::cout << words << " destroyed." << std::endl;
}


void PlaceNew::Show() const
{
    std::cout << words << ", " << number << std::endl;
}

