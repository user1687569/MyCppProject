//Copyright (c) 2022 user1687569
#include <iostream>


int main()
{
    float lightYear;
    std::cout << "=====Light Year-Astronomical units Conversion=====" << std::endl;
    std::cout << "Please input Light Year: ";
    std::cin >> lightYear;   
    std::cout << lightYear << " light years equal to ";
    std::cout << lightYear * 63240 << " astronomical units." << std::endl; 
    return 0;
}

