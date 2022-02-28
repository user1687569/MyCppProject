//Copyright (c) 2022 user1687569
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    char str[20];
    std::cout << "Please, enter a word: ";
    std::cin.get(str, 20, '$');
    std::cout << std::cin.gcount() << " characters read: " << str << '\n';
    char c = std::cin.get();
    std::cout << "c = " << c << std::endl;
    return 0;
}

