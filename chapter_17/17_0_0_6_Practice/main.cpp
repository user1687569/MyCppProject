//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>

int main()
{
    int n;
    std::cout << "Please enter a number: ";
    std::cin >> n;

    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout.setf(std::ios_base::showbase);

    std::cout.width(10);
    std::cout << "Dec: ";
    std::cout.width(10);
    std::cout << "Oct: ";
    std::cout.width(10);
    std::cout << "Hex: ";
    std::cout << std::endl;
    
    std::cout.width(10);
    std::cout << n;

    std::cout << std::oct;
    std::cout.width(10);
    std::cout << n;

    std::cout << std::hex;
    std::cout.width(10);
    std::cout << n;

    return 0;
}


