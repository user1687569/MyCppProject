//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cstring>
#include "list.h"


List::List()
{
    top = 0;
}


void List::menu() const
{
    std::cout << "-----List Menu-----" << std::endl;
    std::cout << "p. push/new a coin" << std::endl;
    std::cout << "a. add price" << std::endl;
    std::cout << "s. substract price" << std::endl;
    std::cout << "d. display list info" << std::endl;
    std::cout << "q. quit" << std::endl;
    std::cout << "-------------------" << std::endl;
}


List & List::addItem(Item & item)
{
    std::cout << "Enter coin name: ";
    std::cin.getline(item.name, Len);
    std::cout << "Enter coin price: ";
    std::cin >> item.price;
    return *this;
}


bool List::isfull() const
{
    return top == ITEM_MAX;
}


bool List::isempty() const
{
    return top == 0;
}


bool List::push(const Item & item)
{
    if(isfull())
    {
        std::cout << "List already full!" << std::endl;
        return false;
    }
    else
    {
        items[top++] = item;
        return true;
    }
}


void List::visit(void (*pf)(Item &))
{
    for(int i = 0; i < top; i++)
        (*pf)(items[i]);
}


void List::display() const
{
    for (int i = 0; i < top; i++)
    {
        std::cout << "Coin name: " << items[i].name << " price: " << items[i].price << std::endl; 
    }
    std::cout << std::endl;
}


void List::addPrice(Item & item)
{
    item.price += 10.0;
}


void List::substractPrice(Item & item)
{
    item.price -= 10.0;
}


