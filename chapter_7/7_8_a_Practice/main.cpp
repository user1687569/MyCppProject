//Copyright (c) 2022 user1687569
#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const char *pSnames[4] = 
    {"Spring", "Summer", "Fall", "Winter"};


void fill(double * pa);
void show(const double * da);


int main()
{
    double *pExpenses = new double[Seasons];
    fill(pExpenses);
    show(pExpenses);

    delete [] pExpenses;
    return 0;
}


void fill(double * pa)
{
    for(int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter: " << pSnames[i] << " expenses: ";
        std::cin >> pa[i];
    }
}


void show(const double * da)
{
    double total = 0.0;
    std::cout << std::endl << "EXPENSES" << std::endl;
    for(int i = 0; i < Seasons; i++)
    {
        std::cout << pSnames[i] << ": $" << da[i] << std::endl;
        total += da[i];
    }

    std::cout << "Total Expenses: $" << total << std::endl;
}



