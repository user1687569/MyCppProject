//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    char firstName[20];
    char lastName[20];
    char grade;
    int age;
    
    std::cout << "What is your first name? ";
    std::cin.getline(firstName, 20);    // std::cout.get(firstName, 20).get();
    
    std::cout << "What is your last name? ";
    std::cin.getline(lastName, 20);     // std::cout.get(lastName, 20).get();
    
    std::cout << "What letter grade do you deserve? ";
    std::cin >> grade;

    std::cout << "What is your age? ";
    std::cin >> age;

    std::cout << std::endl << std::endl;
    std::cout << "Display information: " << std::endl;
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Grade: " << grade << " age: " << age << std::endl;

    return 0;
}




