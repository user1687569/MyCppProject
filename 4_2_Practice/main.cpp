//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::string dessert;

    std::cout << "Enter your name: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter your favorite dessert: " << std::endl;
    std::getline(std::cin, dessert);

    std::cout << std::endl;
    std::cout << "I have some delicious " << dessert;
    std::cout << " for you, " << name << "." << std::endl;

    return 0;
}




