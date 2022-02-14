//Copyright (c) 2022 user1687569
#include <iostream>
#include "list.h"


void addPrice(Item & item);
void substractPrice(Item & item);


int main()
{
    List list;
    Item item;
    char c;

    list.menu();

    while(std::cin >> c && toupper(c) != 'Q')
    {
        while (std::cin.get() != '\n')
            continue;
        if(!isalpha(c))
            continue;

        switch (c)
        {
        case 'p':
        case 'P':
            list.addItem(item);
            list.push(item);           
            break;
        case 'a':
        case 'A':
            list.visit(addPrice);
            break;
        case 's':
        case 'S':
            list.visit(substractPrice);
            break;
        case 'd':
        case 'D':
            list.display();
            break;
        default:
            break;
        }

        list.menu();
    }

    std::cout << "Bye!" << std::endl;

    return 0;
}



void addPrice(Item & item)
{
    item.price += 10.0;
}


void substractPrice(Item & item)
{
    item.price -= 10.0;
}

