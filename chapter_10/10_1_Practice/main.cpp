//Copyright (c) 2022 user1687569
#include <iostream>
#include "bankaccount.h"

int main()
{
    BankAccount Lee("Lee", "3503221996XXX", 168.7);
    Lee.show();

    Lee.deposit(2000.0);
    Lee.show();

    Lee.withdraw(3000.0);
    Lee.show();

    Lee.withdraw(1000.0);
    Lee.show();

    return 0;
}



