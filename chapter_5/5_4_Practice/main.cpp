//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    int year;
    double daphneValue = 100.0;
    double cleoValue = 100.0;

    for(year = 1;; year++)
    {
        daphneValue += 10.0;
        cleoValue *= (1 + 0.05);
        if(cleoValue > daphneValue)
            break;
    }

    std::cout << "After " << year << " years, Celo investment value is larger than Daphne." << std::endl;
    std::cout << "Daphne: " << daphneValue << std::endl;
    std::cout << "Cleo: " << cleoValue << std::endl;

    return 0;
}




