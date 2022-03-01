//Copyright (c) 2022 user1687569
#include <iostream>

class Action
{
    int a;
public:
    Action(int i = 0) : a(i) {}
    int val() const { return a; }
    virtual void f(char ch) const
    { 
        std::cout << val() << ch << "\n"; 
    }
};


class Bingo : public Action
{
public:
    Bingo(int i = 0) : Action(i) {}
    virtual void f(char * ch) const override
    {
        std::cout << val() << ch << "!\n";
    }
};


int main()
{
    Bingo b(10);
    // b.f('@');

    return 0;
}


