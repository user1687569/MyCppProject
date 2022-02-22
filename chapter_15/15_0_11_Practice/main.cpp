//Copyright (c) 2022 user1687569
#include <iostream>
#include "rtti.h"

Grand * GetOne();

int main()
{
    std::srand(std::time(0));
    Grand * pg;
    Superb * ps;

    for(int i = 0; i < 25; i++)
    {
        pg = GetOne();
        pg->Speak();
        if(ps = dynamic_cast<Superb *>(pg))
        {
            ps->Say();
            std::cout << std::endl;
        }
    }

    return 0;
}


Grand * GetOne()
{
    Grand * p;
    switch (std::rand() % 3)
    {
    case 0:
        p = new Grand(std::rand() % 100);
        break;
    case 1:
        p = new Superb(std::rand() % 100);
        break;
    case 2:
        p = new Magnificant(std::rand() % 100,
                    'A' + std::rand() % 26);
        break;
    default:
        break;
    }

    return p;
}


