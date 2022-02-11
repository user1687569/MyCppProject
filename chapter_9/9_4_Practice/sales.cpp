//Copyright (c) 2022 user1687569
#include <iostream>
#include <limits>
#include "sales.h"

namespace SALES
{

void setSales(Sales & s, const double ar[], int n)
{
    double min = INT64_MAX;
    double max = INT64_MIN;
    double sum = 0.0;
    for(int i = 0; i < n && i < 4; i++)
    {
        min = min < ar[i] ? min : ar[i];
        max = max > ar[i] ? max : ar[i];
        sum += ar[i];
        s.sales[i] = ar[i];
    }

    s.average = sum / n;
    s.max = max;
    s.min = min;
}

void setSales(Sales & s)
{
    int i;
    double min = INT64_MAX;
    double max = INT64_MIN;
    double sum = 0.0;

    std::cout << "Please enter four quarter sale: " << std::endl;
    for(i = 0; i < QUARTERS; i++)
    {
        std::cout << "Quarter " << i + 1 << ": ";
        while(!(std::cin >> s.sales[i]))
        {
            std::cin.clear();   
            //std::cin.ignore(10000, '\n);
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input; Please enter a number: ";
        }
    }

    for(i = 0; i < QUARTERS; i++)
    {
        min = min < s.sales[i] ? min : s.sales[i];
        max = max > s.sales[i] ? max : s.sales[i];
        sum += s.sales[i];
    }

    s.average = sum / QUARTERS;
    s.max = max;
    s.min = min;
}


void showSales(const Sales & s)
{
    std::cout << "Sales Info: " << std::endl;
    for(int i = 0; i < QUARTERS; i++)
    {
        std::cout << "Quarter " << i + 1 << " Sale: " << s.sales[i] << std::endl;
    }
    std::cout << "Max Sale: " << s.max << std::endl;
    std::cout << "Min Sale: " << s.min << std::endl;
    std::cout << "Average Sale: " << s.average << std::endl;
}



}



