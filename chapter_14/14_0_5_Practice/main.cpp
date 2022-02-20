//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"


int main()
{
    Stack<std::string> st;
    char ch;
    std::string po;

    std::cout << "Please enter A to add a purchase order, " << std::endl
              << "P to process a purchase order, or Q to quit." << std::endl;
    while (std::cin >> ch && std::toupper(ch) != 'Q')
    {
        while (std::cin.get() != '\n')
            continue;
        if(!std::isalpha(ch))
        {
            std::cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            std::cout << "Enter a purchase order number to add: ";
            std::cin >> po;
            if(st.isfull())
                std::cout << "stack already full" << std::endl;
            else
                st.push(po);
            break;
        case 'P':
        case 'p':
            if(st.isempty())
                std::cout << "stack already empty" << std::endl;
            else
            {
                st.pop(po);
                std::cout << "Purchase Order #" << po << " popped" << std::endl;
                break;
            }
        default:
            break;
        }
        std::cout << "Please enter A to add a purchase order, " << std::endl
                  << "P tp process a purchase order, or Q to quit." << std::endl;
    }

    std::cout << "Bye" << std::endl;
    return 0;
}




