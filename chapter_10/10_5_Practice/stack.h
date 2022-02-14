//Copyright (c) 2022 user1687569
#ifndef _STACK_H_
#define _STACK_H_

const int Len = 35;

struct customer
{
    char fullname[Len];
    double payment;
};

typedef struct customer Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    double sum;
    int top;

public:
    Stack();
    Stack & addCustomer(Item & item);
    double getSum();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};


#endif