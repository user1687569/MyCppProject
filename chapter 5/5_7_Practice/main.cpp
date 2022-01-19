//Copyright (c) 2022 user1687569
#include <iostream>
#include <vector>
#include <string>

struct Car
{
    std::string brand;
    int year;
};

int main()
{
    int i;
    int catalog;

    std::cout << "How many cars do you wish to catalog? ";
    std::cin >> catalog;

    Car* carList = new Car[catalog];
    for(i = 0; i < catalog; i++)
    {
        std::cout << "Car #" << i + 1 << ":" << std::endl;
        std::cout << "Please enter the make: ";
        std::cin.sync();        //clear buffer
        std::getline(std::cin, carList[i].brand);
        std::cout << "Please enter the year make: ";
        std::cin >> carList[i].year;
    }

    std::cout << "Here is your collection: " << std::endl;
    for(i = 0; i < catalog; i++)
    {
        std::cout << carList[i].year << " " << carList[i].brand << std::endl;
    }

    delete [] carList;

    return 0;
}




