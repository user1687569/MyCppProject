//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "worker.h"

const int SIZE = 4;

int main()
{
    Worker * lolas[SIZE];
    int ct;

    for(ct = 0; ct < SIZE; ct++)
    {
        char choice;
        std::cout << "Enter the employee category: " << std::endl
                  << "w: waiter     s: singer     "
                  << "t: singing waiter     q: quit" << std::endl;
        std::cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            std::cout << "Please enter a w, s, t, or q: ";
            std::cin >> choice;
        }

        if(choice == 'q')
            break;
        
        switch (choice)
        {
        case 'w':
            lolas[ct] = new Waiter;
            break;
        case 's':
            lolas[ct] = new Singer;
            break;
        case 't':
            lolas[ct] = new SingingWaiter;
            break;
        default:
            break;
        }
        std::cin.get();
        lolas[ct]->Set();
    }

    std::cout << std::endl << "Here is your staff: " << std::endl;

    int i;
    for(i = 0; i < ct; i++)
    {
        std::cout << std::endl;
        lolas[i]->Show();
    }

    for(i = 0; i < ct; i++)
        delete lolas[i];

    std::cout << "Bye." << std::endl;
    return 0;
}




