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
    Pizza* pizzaList = new Pizza[3];
    
    std::cout << "Input first type pizza information: " << std::endl;
    std::cout << "Enter pizza corporation: ";
    std::cin.getline(pizzaList[0].corporation, 20);
    std::cout << "Enter pizza diameter: ";
    std::cin >> pizzaList[0].diameter;
    std::cout << "Enter pizza weight: ";
    std::cin >> pizzaList[0].weight;

    std::cout << std::endl;
    std::cout << "Input second type pizza information: " << std::endl;
    std::cout << "Enter pizza corporation: ";
    std::cin.get();
    std::cin.getline(pizzaList[1].corporation, 20);
    std::cout << "Enter pizza diameter: ";
    std::cin >> pizzaList[1].diameter;
    std::cout << "Enter pizza weight: ";
    std::cin >> pizzaList[1].weight;

    std::cout << std::endl;
    std::cout << "Display Pizza Info: " << std::endl;
    std::cout << "Corporation: " << pizzaList[0].corporation << std::endl;
    std::cout << "Diameter: " << pizzaList[0].diameter << std::endl;
    std::cout << "Weight: " << pizzaList[0].weight << std::endl;
    std::cout << "Corporation: " << pizzaList[1].corporation << std::endl;
    std::cout << "Diameter: " << pizzaList[1].diameter << std::endl;
    std::cout << "Weight: " << pizzaList[1].weight << std::endl;

    delete [] pizzaList;
    return 0;
}




