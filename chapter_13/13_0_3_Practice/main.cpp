//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include "brassABC.h"

const int CLIENTS = 4;

int main()
{
    BrassABC * pClients[CLIENTS];
    std::string temp;
    long tempNum;
    double tempBal;
    char kind;

    for(int i = 0; i < CLIENTS; i++)
    {
        std::cout << "Enter client's name: ";
        std::getline(std::cin, temp);
        
        std::cout << "Enter client's account number: ";
        std::cin >> tempNum;

        std::cout << "Enter opening balance: $";
        std::cin >> tempBal;

        std::cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        
        while (std::cin >> kind && (kind != '1' && kind != '2'))
            std::cout << "Enter either 1 or 2: ";
        if(kind == '1')
            pClients[i] = new Brass(temp, tempNum, tempBal);
        else
        {
            double tempMax, tempRate;
            std::cout << "Enter the overdraft limit: $";
            std::cin >> tempMax;
            std::cout << "Enter the interest rate "
                      << "as a decimal fraction: ";
            std::cin >> tempRate;
            pClients[i] = new BrassPlus(temp, tempNum, tempBal,
                                        tempMax, tempRate);
        }
        while (std::cin.get() != '\n')
            continue;
    }
    std::cout << std::endl;
    for(int i = 0; i < CLIENTS; i++)
    {
        pClients[i]->ViewAcct();
        std::cout << std::endl;
    }

    for(int i = 0; i < CLIENTS; i++)
    {
        delete pClients[i];
    }
    std::cout << "Done." << std::endl;

    return 0;
}



