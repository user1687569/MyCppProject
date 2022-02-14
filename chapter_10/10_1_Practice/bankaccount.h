//Copyright (c) 2022 user1687569
#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include <iostream>

class BankAccount
{
private:
    char name[40];
    char account[25];
    double balance;

public:
    BankAccount(const char * client, const char * num, double bal = 0.0);
    // 括号后的const表明，该函数不会修改被隐式访问的对象
    void show(void) const;
    void deposit(double cash);
    void withdraw(double cash);
};


#endif