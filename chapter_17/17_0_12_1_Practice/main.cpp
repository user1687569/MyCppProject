//Copyright (c) 2022 user1687569
#include <iostream>

// Today is a good day. HHHH
// Today is a good day

int main()
{
    int count = 0;
    char great_input[80];
    char ch;
    int i = 0;
    while ((ch = std::cin.peek()) != '.' && ch != '\n')
    {
        std::cin.get(great_input[i++]);
    }

    great_input[i] = '\0';   
    std::cout << great_input << std::endl;

    std::cin.clear();
    while(std::cin.get() != '\n')
        continue;
    
    // Please, enter a word: Simplify
    // 9 characters read: Simplify
    char str[20];
    std::cout << "Please, enter a word: ";
    std::cin.getline(str,20);
    std::cout << std::cin.gcount() << " characters read: " << str << '\n';

    return 0;
}


