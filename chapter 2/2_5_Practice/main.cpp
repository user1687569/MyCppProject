//Copyright (c) 2022 user1687569
#include <iostream>


int main()
{
    float celsius;
    std::cout << "=====Fahrenheit-Celsius degree Conversion=====" << std::endl;
    std::cout << "Please input Celsis degrees: ";
    std::cin >> celsius;   
    std::cout << celsius << " degrees Celsius is ";
    std::cout << celsius * 1.8 + 32 << " degrees Fahrenheit." << std::endl; 
    return 0;
}

