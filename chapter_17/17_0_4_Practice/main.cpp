//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    int w = std::cout.width(30);
    std::cout << "default filed width = " << w << ":\n";
    std::cout.width(5);
    std::cout << "N" << ':';
    std::cout.width(8);
    std::cout << "N * N" << ":\n";

    for(long i = 1; i <= 100; i *= 10)
    {
        std::cout.width(5);
        std::cout << i << ':';
        std::cout.width(8);
        std::cout << i * i << ":\n";
    }

    std::cout.fill('*');
    const char * staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper" };
    long bonus[2] = {900, 1350};

    for(int i = 0; i < 2; i++)
    {
        std::cout << staff[i] << ": $";
        std::cout.width(7);
        std::cout << bonus[i] << "\n";
    }

    std::cout << std::endl << std::endl;
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    std::cout << "\"Furry Friends\" is $" << price1 << "!\n";
    std::cout << "\"Fiery Friends\" is $" << price2 << "!\n";
    std::cout << std::endl;

    std::cout.precision(2);
    std::cout << "\"Furry Friends\" is $" << price1 << "!\n";
    std::cout << "\"Fiery Friends\" is $" << price2 << "!\n";
    std::cout << std::endl;

    std::cout.setf(std::ios_base::showpoint);
    std::cout << "\"Furry Friends\" is $" << price1 << "!\n";
    std::cout << "\"Fiery Friends\" is $" << price2 << "!\n";
    std::cout << std::endl;

    std::cout.precision(8);
    std::cout << "\"Furry Friends\" is $" << price1 << "!\n";
    std::cout << "\"Fiery Friends\" is $" << price2 << "!\n";
    std::cout << std::endl;

    return 0;
}


