//Copyright (c) 2022 user1687569
#include <iostream>
#include "wine.h"


int main()
{
    std::cout << "Enter name of wine: ";
    char lab[50];
    std::cin.get(lab, 50);
    
    std::cout << "Enter number of years: ";
    int year;
    std::cin >> year;

    Wine holding(lab, year);
    holding.GetBottles();
    holding.Show();

    const int YEAR = 3;
    int y[YEAR] = {1993, 1995, 1998};
    int b[YEAR] = {48, 60, 72};

    Wine more("Gushing Grape Red", YEAR, y, b);
    more.Show();

    std::cout << "Total bottles for " << more.Label()
              << ": " << more.sum() << std::endl;
    std::cout << "Bye" << std::endl;

    return 0;
}


