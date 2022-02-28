//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>

struct Employee
{
    std::string name;
    double wages;
    double hours;
};


int main()
{
    Employee employee;
    std::cout << "Enter your name: ";
    std::getline(std::cin, employee.name);
    
    std::cout << "Enter your hourly wages: ";
    std::cin >> employee.wages;

    std::cout << "Enter number of hours worked: ";
    std::cin >> employee.hours;

    std::cout << "First format:" << std::endl;
    std::cout.setf(std::ios_base::showbase);
    std::cout.width(20);
    std::cout << employee.name;
    std::cout << ": $";
    std::cout.width(10);
    std::cout << employee.wages;
    std::cout << ":";
    std::cout.width(10);
    std::cout << employee.hours;
    std::cout << std::endl;
    
    std::cout << "Second format:" << std::endl;
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout.width(20);
    std::cout << employee.name;
    std::cout << ": $";
    std::cout.width(10);
    std::cout << employee.wages;
    std::cout << ":";
    std::cout.width(10);
    std::cout << employee.hours;
    std::cout << std::endl;

    return 0;
}


