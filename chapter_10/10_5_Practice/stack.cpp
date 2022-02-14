//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cstring>
#include "stack.h"

Stack::Stack()
{
    top = 0;
    sum = 0.0;
}


Stack & Stack::addCustomer(Item & item)
{
    std::cout << "Enter customer name: ";
    std::cin.getline(item.fullname, Len);
    std::cout << "Enter customer payment: ";
    std::cin >> item.payment;
    return *this;
}


double Stack::getSum()
{
    return sum;
}


bool Stack::isempty() const
{
    return top == 0;
}


bool Stack::isfull() const
{
    return top == MAX;
}


bool Stack::push(const Item & item)
{
    if(top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}


bool Stack::pop(Item &item)
{
    if(top > 0)
    {
        item = items[--top];
        sum += item.payment;
        return true;
    }
    else
        return false;
}


