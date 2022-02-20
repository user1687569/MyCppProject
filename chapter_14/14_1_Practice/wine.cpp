//Copyright (c) 2022 user1687569
#include <iostream>
#include "wine.h"


Wine::Wine(): label("none"), yearCount(0), pairArray(ArrayInt(0), ArrayInt(0))
{
}


Wine::Wine(const char * l, int y, const int yr[], const int bot[])
{
    label = l;
    yearCount = y;
    pairArray = PairArray(ArrayInt(yr, y), ArrayInt(bot, y));
}


Wine::Wine(const char * l, int y)
{
    label = l;
    yearCount = y;
    pairArray = PairArray(ArrayInt(y), ArrayInt(y));
}


Wine::~Wine()
{
}


void Wine::GetBottles()
{
    int y, b;
    std::cout << "Enter " << label << " pairArray for " << yearCount << "year(s)" << std::endl;
    for(int i = 0; i < yearCount; i++)
    {
        std::cout << "Enter year: ";
        std::cin >> y;
        pairArray.first()[i] = y;
        std::cout << "Enter bottles for that year: ";
        std::cin >> b;
        pairArray.second()[i] = b;
    } 
}


std::string & Wine::Label()
{
    return label;
}


void Wine::Show()
{
    std::cout << "Wine Brand: " << label << std::endl;
    for(int i = 0; i < yearCount; i++)
    {
        std::cout << "Wine Year: " << pairArray.first()[i] 
                  << ", Wine Bottles: " << pairArray.second()[i] << std::endl;
    }
}


int Wine::sum()
{   
    return pairArray.second().sum();
}

