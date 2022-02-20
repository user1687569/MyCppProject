//Copyright (c) 2022 user1687569
#include <iostream>
#include "wine.h"


Wine::Wine(): std::string("none"), yearCount(0), PairArray(ArrayInt(0), ArrayInt(0))
{
}


Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : std::string(l), yearCount(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{
}


Wine::Wine(const char * l, int y)
    : std::string(l), yearCount(y), PairArray(ArrayInt(y), ArrayInt(y))
{
}


Wine::~Wine()
{
}


void Wine::GetBottles()
{
    int y, b;
    std::cout << "Enter " << Label() << " pairArray for " << yearCount << "year(s)" << std::endl;
    for(int i = 0; i < yearCount; i++)
    {
        std::cout << "Enter year: ";
        std::cin >> y;
        PairArray::first()[i] = y;
        std::cout << "Enter bottles for that year: ";
        std::cin >> b;
        PairArray::second()[i] = b;
    } 
}


std::string & Wine::Label()
{
    return (std::string &)(*this);
}


void Wine::Show()
{
    std::cout << "Wine Brand: " << Label() << std::endl;
    for(int i = 0; i < yearCount; i++)
    {
        std::cout << "Wine Year: " << PairArray::first()[i] 
                  << ", Wine Bottles: " << PairArray::second()[i] << std::endl;
    }
}


int Wine::sum()
{   
    return PairArray::second().sum();
}

