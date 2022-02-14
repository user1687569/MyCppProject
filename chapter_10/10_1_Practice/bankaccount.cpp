//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "bankaccount.h"


BankAccount::BankAccount(const char * client, const char * num, double bal)
{
    strcpy(name, client);
    strcpy(account, num);
    balance = bal;
}


void BankAccount::show(void) const
{
    std::cout << "Bank Account Information: " << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Account: " << account << std::endl;
    std::cout << "Balance: " << balance << std::endl << std::endl;
}


void BankAccount::deposit(double cash)
{
    if(cash < 0)
        std::cout << "Deposits can't be less than 0" << std::endl;
    else
        balance += cash;
}


void BankAccount::withdraw(double cash)
{
    if(cash < 0)
        std::cout << "Withdraw money can't be less than 0" << std::endl;
    else if(cash > balance)
        std::cout << "You can't withdraw more than you have!" << std::endl;
    else
        balance -= cash;
}






