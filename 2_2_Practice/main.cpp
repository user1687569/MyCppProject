//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    int longDistance;
    std::cout << "=====Distance Conversion=====" << std::endl;
    std::cout << "Please Input a distance (unit: long): " << std::endl;
    std::cin >> longDistance;
    std::cout << "After conversion, distance (unit: long) is: ";
    std::cout << longDistance * 220 << " yard." << std::endl;
    return 0;
}
