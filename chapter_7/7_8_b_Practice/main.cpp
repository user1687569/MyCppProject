//Copyright (c) 2022 user1687569
#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const char *pSnames[4] = 
    {"Spring", "Summer", "Fall", "Winter"};

struct ST_Expenses
{
    double expense; 
};

void fill(ST_Expenses * pa);
void show(const ST_Expenses * da);

int main()
{
    ST_Expenses *pExpenses = new ST_Expenses[Seasons];
    fill(pExpenses);
    show(pExpenses);

    delete [] pExpenses;
    return 0;
}

void fill(ST_Expenses * pa)
{
    for(int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter: " << pSnames[i] << " expenses: ";
        std::cin >> pa[i].expense;
    }
}

void show(const ST_Expenses * da)
{
    double total = 0.0;
    std::cout << std::endl << "EXPENSES" << std::endl;
    for(int i = 0; i < Seasons; i++)
    {
        std::cout << pSnames[i] << ": $" << da[i].expense << std::endl;
        total += da[i].expense;
    }

    std::cout << "Total Expenses: $" << total << std::endl;
}



