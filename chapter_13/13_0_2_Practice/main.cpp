//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include "brass.h"

const int CLIENTS = 4;


int main()
{
    // Brass Piggy("Porcelot Piggy", 381299, 4000.00);
    // BrassPlus Hoggy("Horatio Hoggy", 382288, 3000.00);

    // Piggy.ViewAcct();
    // std::cout << std::endl;

    // Hoggy.ViewAcct();
    // std::cout << std::endl;

    // std::cout << "Depositing $1000 into the Hoggy Account: " << std::endl;
    // Hoggy.Deposit(1000.00);
    // std::cout << "New balance: $" << Hoggy.Balance() << std::endl;
    
    // std::cout << "Withdrawing $4200 from the Piggy Account: " << std::endl;
    // Piggy.Withdraw(4200.00);
    // std::cout << "Piggy account balance: $" << Piggy.Balance() << std::endl << std::endl;
    
    // std::cout << "Withdrawing $4200 form the Hoggy Account:" << std::endl;
    // Hoggy.Withdraw(4200.00);
    // Hoggy.ViewAcct();

    Brass * pClients[CLIENTS];
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

        std::cout << "Enter 1 for Brass Account or "
                  << "2 for BrassPlus Account: ";
        while (std::cin >> kind && (kind != '1' && kind != '2'))
        {
            std::cout << "Enter either 1 or 2: ";
        }
        
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
            pClients[i] = new BrassPlus(temp, tempNum, tempBal, tempMax, tempRate);
        }
        
        while (std::cin.get() != '\n')
            continue;
    }

    std::cout << std::endl;
    for(int i = 0; i < CLIENTS; i++)
    {
        // 多态性
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

