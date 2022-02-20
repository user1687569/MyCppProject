//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include <ctime>
#include "person.h"

const int SIZE = 4;

int main()
{
    Person * personList[SIZE];
    int ct;

    for(ct = 0; ct < SIZE; ct++)
    {
        char choice;
        std::cout << "Enter person category: " << std::endl
                  << "g: Gunslinger     p: PokerPlayer     "
                  << "b: BadDude     q: quit" << std::endl;
        std::cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
            std::cout << "Please enter a g, p, b or q: ";
            std::cin >> choice;
        }

        if(choice == 'q')
            break;
        
        switch (choice)
        {
        case 'g':
            personList[ct] = new Gunslinger;
            break;
        case 'p':
            personList[ct] = new PokerPlayer;
            break;
        case 'b':
            personList[ct] = new BadDude;
            break;
        default:
            break;
        }
        std::cin.get();
        personList[ct]->Set();
    }

    std::cout << std::endl << "Here is person list: " << std::endl;

    int i;
    for(i = 0; i < ct; i++)
    {
        std::cout << std::endl;
        personList[i]->Show();
    }

    for(i = 0; i < ct; i++)
        delete personList[i];

    std::cout << "Bye." << std::endl;
    return 0;
}


