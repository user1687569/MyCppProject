//Copyright (c) 2022 user1687569
#include <iostream>


struct Pizza
{
    char corporation[20];
    double diameter;
    double weight;
};


int main()
{
    Pizza pizzaOne;
    
    std::cout << "Enter pizza corporation: ";
    std::cin.getline(pizzaOne.corporation, 20);

    std::cout << "Enter pizza diameter: ";
    std::cin >> pizzaOne.diameter;

    std::cout << "Enter pizza weight: ";
    std::cin >> pizzaOne.weight;

    std::cout << "Pizza Info: " << std::endl;
    std::cout << "Corporation: " << pizzaOne.corporation << std::endl;
    std::cout << "Diameter: " << pizzaOne.diameter << std::endl;
    std::cout << "Weight: " << pizzaOne.weight << std::endl;

    return 0;
}




