//Copyright (c) 2022 user1687569
#include <iostream>
#include "worker.h"

const int LIM = 4;

int main()
{
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waiter waiterTemp;
    Singer singerTemp;

    Worker * pw[LIM] = {&bob, &bev, &waiterTemp, &singerTemp};

    int i;
    for(i = 2; i < LIM; i++)
        pw[i]->Set();

    for(i = 0; i < LIM; i++)
    {
        pw[i]->Show();
        std::cout << std::endl;
    }

    return 0;
}




