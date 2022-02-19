//Copyright (c) 2022 user1687569
#include <iostream>
#include "dmaABC.h"

const int COUNT = 4;

int main()
{
    DMAABC * pDMAs[COUNT];
    char tempLabel[50];
    int tempRating;
    char tempColor[40];
    char tempStyle[40];

    std::string temp;
    long tempNum;
    double tempBal;
    char kind;

    for(int i = 0; i < COUNT; i++)
    {
        std::cout << "Enter DMA's label: ";
        std::cin.getline(tempLabel, 50);
        
        std::cout << "Enter DMA's rating: ";
        while(!(std::cin >> tempRating))
        {   
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input; Please enter a number: ";
        }
        
        std::cout << "Enter 1 for baseDMA or 2 for lacksDMA or 3 for hasDMA: ";
        
        while (std::cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
            std::cout << "Enter either 1 or 2 or 3: ";
        if(kind == '1')
            pDMAs[i] = new baseDMA(tempLabel, tempRating);
        else if (kind == '2')
        {
            while (std::cin.get() != '\n')
                continue;
            char tempColor[40];
            std::cout << "Enter DMA color: ";
            std::cin.getline(tempColor, 40);
            pDMAs[i] = new lacksDMA(tempColor, tempLabel, tempRating);
        }
        else
        {
            while (std::cin.get() != '\n')
                continue;
            char tempStyle[40];
            std::cout << "Enter DMA style: ";
            std::cin.getline(tempStyle, 40);
            pDMAs[i] = new hasDMA(tempStyle, tempLabel, tempRating);
        }
        while (std::cin.get() != '\n')
            continue;
    }
    std::cout << std::endl;
    for(int i = 0; i < COUNT; i++)
    {
        pDMAs[i]->View();
        std::cout << std::endl;
    }

    for(int i = 0; i < COUNT; i++)
    {
        delete pDMAs[i];
    }
    std::cout << "Done." << std::endl;

    return 0;
}




