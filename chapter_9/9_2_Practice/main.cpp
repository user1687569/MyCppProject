//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>

const int ArSize = 10;

void strcount(const std::string str);

int main()
{
    std::string input;
    char next;

    std::cout << "Enter a line: " << std::endl;
    std::getline(std::cin, input);
    while (std::cin && input != "")
    {
        strcount(input);
        std::cout << "Enter next line (empty line to quit): " << std::endl;
        std::getline(std::cin, input);
    }

    std::cout << "Bye" << std::endl;
    return 0;
}


void strcount(const std::string str)
{
    static int total = 0;
    int count = 0;
    
    std::cout << "\"" << str << "\" contains ";
    count += str.length();
    total += count;

    std::cout << count << " characters" << std::endl;
    std::cout << total << " characters total" << std::endl;
}
