//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>

int main()
{
    char firstName[20];
    char lastName[20];
    char fullName[40];

    std::cout << "Enter your first name: ";
    std::cin.getline(firstName, 20);

    std::cout << "Enter your last name: ";
    std::cin.getline(lastName, 20);

    strcpy(fullName, firstName);
    strcat(fullName, ", ");
    strcat(fullName, lastName);

    std::cout << "Here's the information in a single string: " << fullName << std::endl;
    
    return 0;
}




