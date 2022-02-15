//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>

int main()
{
    char automobile[50];
    int year;
    double a_price;
    double d_price;

    std::ofstream outFile;
    outFile.open("carinfo.txt");

    std::cout << "Enter the make and model of automobile: ";
    std::cin.getline(automobile, 50);
    
    std::cout << "Enter the model year: ";
    std::cin >> year;

    std::cout << "Enter the original asking price: ";
    std::cin >> a_price;
    d_price = 0.913 * a_price;

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout.setf(std::ios_base::showpoint);

    std::cout << "Make and model: " << automobile << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Was asking $" << a_price << std::endl;
    std::cout << "Now asking $" << d_price << std::endl;

    outFile << std::fixed;
    outFile.precision(2);
    outFile.setf(std::ios_base::showpoint);
    outFile << "Make and model: " << automobile << std::endl;
    outFile << "Year: " << year << std::endl;
    outFile << "Was asking $" << a_price << std::endl;
    outFile << "Now asking $" << d_price << std::endl;
    outFile.close();

    return 0;
}

