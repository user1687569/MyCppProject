//Copyright (c) 2022 user1687569
#include <iostream>
#include "stack.h"

Stack::Stack(int n)
{
    n = n < Stack::MAX ? n : Stack::MAX; 
    size = n;
    pitems = new Item[size];
    top = 0;    
}


Stack::Stack(const Stack & st)
{
    size = st.size;
    top = st.top;
    delete [] pitems;
    pitems = new Item[size];
    for(int i = 0; i < size; i++)
        pitems[i] = st.pitems[i];
}


Stack::~Stack()
{
    delete [] pitems;
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
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}


bool Stack::pop(Item &item)
{
    if(top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}


Stack & Stack::operator=(const Stack & st)
{
    size = st.size;
    top = st.top;
    delete [] pitems;
    pitems = new Item[size];
    for(int i = 0; i < size; i++)
        pitems[i] = st.pitems[i];

    return *this;
}


