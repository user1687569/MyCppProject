//Copyright (c) 2022 user1687569
#include <iostream>

const int SLEN = 10;
inline void eatline() { while (std::cin.get() != '\n') continue; }


int main()
{
    char name[SLEN];
    char title[SLEN];
    std::cout << "Enter your name: ";
    std::cin.get(name, SLEN);
    if(std::cin.peek() != '\n')
        std::cout << "Sorry, we only have enough room for "
                  << name << std::endl;
    
    eatline();

    std::cout << "Dear " << name << ", enter your title: \n";
    std::cin.get(title, SLEN);
    if(std::cin.peek() != '\n')
        std::cout << "We were forced to truncate your title.\n";
    eatline();

    std::cout << " Name: " << name
              << "\nTitle: " << title << std::endl;

    return 0;
}


