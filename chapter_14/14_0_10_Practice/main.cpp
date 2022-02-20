//Copyright (c) 2022 user1687569
#include <iostream>
#include "tempparm.h"


int main()
{
    Crab<Stack> nebula;

    int ni;
    double nb;
    std::cout << "Enter int double pairs, such as 4 3.5 (0 0 to end): " << std::endl;
    while (std::cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if(!nebula.push(ni, nb))
            break;
    }

    while (nebula.pop(ni, nb))
        std::cout << ni << ", " << nb << std::endl;
    
    std::cout << "Done." << std::endl;
    return 0;
}


