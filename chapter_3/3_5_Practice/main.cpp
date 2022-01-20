//Copyright (c) 2022 user1687569
#include <iostream>
#include <climits>
#include <cmath>

//Population of China(2022-1-15): 1,451,719,774
//Population of World(2022-1-15): 7,952,023,710

int main()
{
    long long populationOfWorld;
    long long populationOfChina;
    double percentage;
    std::cout << "Enter the world's population: ";
    std::cin >> populationOfWorld;
    std::cout << "Enter the population of the China: ";
    std::cin >> populationOfChina;
    percentage = (populationOfChina * 100.0) / populationOfWorld;
    std::cout << "The population of the China is " << percentage << "% of the world opulation.";
    return 0;
}


