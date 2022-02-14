//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "golf.h"


Golf::Golf(const char * name, int hc)
{   
    strcpy(fullname, name);
    handicap = hc;
}


Golf & Golf::setGolf(int & result)
{
    std::cout << "Enter golf name: ";
    std::cin.getline(fullname, Len);
    if(strlen(fullname) != 0)
        result = 1;

    std::cout << "Enter golf handicap: ";
    std::cin >> handicap;

    return *this;
}


void Golf::setHandicap(int &hc)
{
    handicap = hc;
}


void Golf::showgolf() const
{
    std::cout << "Golf fullname: " << fullname << ", handicap: " << handicap << std::endl;
}


