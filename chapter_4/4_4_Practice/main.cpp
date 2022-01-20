//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>

int main()
{
    std::string firstName;
    std::string lastName;
    std::string fullName;

    std::cout << "Enter your first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter your last name: ";
    std::getline(std::cin, lastName);

    fullName = firstName + ", ";
    fullName += lastName;

    std::cout << "Here's the information in a single string: " << fullName << std::endl;
    
    return 0;
}




