//Copyright (c) 2022 user1687569
#include <iostream>

enum incomeLevel
{
    levelA,
    levelB,
    levelC,
    levelD,
    levelNULL
};

int main()
{
    double income;
    double taxes;
    incomeLevel inputLevel;
    std::cout << "Please enter income: ";

    while (std::cin >> income)
    {
        if(income < 0)
            break;
        else if(income <= 5000.0)
            inputLevel = levelA;
        else if(income > 5000.0 && income <= 15000.0)
            inputLevel = levelB;
        else if(income > 15000.0 && income <= 35000.0)
            inputLevel = levelC;
        else if(income > 35000.0)
            inputLevel = levelD;
        else
            inputLevel = levelNULL;
        
        switch (inputLevel)
        {
        case levelA:
            taxes = 0;
            break;
        case levelB:
            taxes = (income - 5000.0) * 0.1;
            break;
        case levelC:
            taxes = 10000 * 0.1 + (income - 15000) * 0.15; 
            break;
        case levelD:
            taxes = 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
            break;
        default:
            break;
        }
        std::cout << "Income: " << income << " tvarps, Tax: " << taxes << " tvarps." << std::endl;
        std::cout << "Enter next income: ";
    }
    
    std::cout << "Byebye!" << std::endl;
    return 0;
}



