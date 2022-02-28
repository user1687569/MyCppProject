//Copyright (c) 2022 user1687569
#include <iostream>

// I C++ clearly.
// I C++ clearly.14
// I C++ clearly.
// IC++clearly.

int main()
{
    int ct = 0;
    char ch;
    std::cin.get(ch);

    // I C++ clearly.
    // I C++ clearly.14
    while (ch != '\n')
    {
        std::cout << ch;
        ct++;
        std::cin.get(ch);
    }
    std::cout << ct << std::endl;


    ct = 0;
    std::cin >> ch; // 跳过空格，换行符，制表符

    // I C++ clearly.
    // IC++clearly.
    while (ch != '\n')
    {
        std::cout << ch;
        ct++;
        std::cin >> ch;
    }
    std::cout << ct << std::endl;

    return 0;
}


