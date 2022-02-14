//Copyright (c) 2022 user1687569
#ifndef _LIST_H_
#define _LIST_H_

const int Len = 25;

struct Coin
{
    char name[Len];
    double price;
};

typedef struct Coin Item;

class List
{
private:
    static const int ITEM_MAX = 5;
    Item items[ITEM_MAX];
    int top;

public:
    List();
    void menu() const;
    List & addItem(Item & item);
    bool isfull() const;
    bool isempty() const;
    bool push(const Item & item);
    void visit(void (*pf)(Item &));
    void display() const;
    void addPrice(Item &);
    void substractPrice(Item &);
};


#endif