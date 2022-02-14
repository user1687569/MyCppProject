//Copyright (c) 2022 user1687569
#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    Stack st;
    char ch;
    Item item;
    
    std::cout << std::endl << "Please enter A to add/push a customer, " << std::endl
              << "P to pop a customer, or Q to quit." << std::endl;

    while (std::cin >> ch && toupper(ch) != 'Q')
    {
        while (std::cin.get() != '\n')
            continue;
        if(!isalpha(ch))
        {
            std::cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a':
            std::cout << "Enter a customer to add/push: " << std::endl;
            st.addCustomer(item);
            if(st.isfull())
                std::cout << "stack already full" << std::endl;
            else
                st.push(item);
            break;
        case 'P':
        case 'p':
            if(st.isempty())
                std::cout << "stack already empty" << std::endl;
            else{
                st.pop(item);
                std::cout << "Customer poped, Name: [" << item.fullname << "] Payment: [" << item.payment << "]" << std::endl;
                std::cout << "Current Payment Sum is: [" << st.getSum() << "]" << std::endl;
            }
            break;
        default:
            break;
        }
        std::cout << std::endl << "Please enter A to add/push a customer, " << std::endl
                  << "P to pop a customer, or Q to quit." << std::endl;
    }

    std::cout << "Bye" << std::endl;
    return 0;
}



