//Copyright (c) 2022 user1687569
#include <iostream>
#include <limits>
#include "sales.h"

namespace SALES
{
Sales::Sales(const double ar[], int n)
{
    double min = INT64_MAX;
    double max = INT64_MIN;
    double sum = 0.0;
    for(int i = 0; i < n && i < 4; i++)
    {
        min = min < ar[i] ? min : ar[i];
        max = max > ar[i] ? max : ar[i];
        sum += ar[i];
        m_sales[i] = ar[i];
    }

    m_average = sum / n;
    m_max = max;
    m_min = min;
}


Sales & Sales::setSales()
{
    int i;
    double min = INT64_MAX;
    double max = INT64_MIN;
    double sum = 0.0;

    std::cout << "Please enter four quarter sale: " << std::endl;
    for(i = 0; i < QUARTERS; i++)
    {
        std::cout << "Quarter " << i + 1 << ": ";
        while(!(std::cin >> m_sales[i]))
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
        min = min < m_sales[i] ? min : m_sales[i];
        max = max > m_sales[i] ? max : m_sales[i];
        sum += m_sales[i];
    }

    m_average = sum / QUARTERS;
    m_max = max;
    m_min = min;

    return *this;
}


void Sales::showSales() const
{
    std::cout << "Sales Info: " << std::endl;
    for(int i = 0; i < QUARTERS; i++)
    {
        std::cout << "Quarter " << i + 1 << " Sale: " << m_sales[i] << std::endl;
    }
    std::cout << "Max Sale: " << m_max << std::endl;
    std::cout << "Min Sale: " << m_min << std::endl;
    std::cout << "Average Sale: " << m_average << std::endl;
}
}

