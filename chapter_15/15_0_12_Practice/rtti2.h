//Copyright (c) 2022 user1687569
#ifndef _SALES_H_
#define _SALES_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


class Grand
{
private:
    int hold;

public:
    Grand(int h = 0) : hold(h) {}
    virtual void Speak() const { std::cout << "I am a grand class!" << std::endl; }
    virtual int Value() const { return hold; }
};


class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h) {}
    void Speak() const { std::cout << "I am a superb class!!" << std::endl; }
    virtual void Say() const 
        { std::cout << "I hold the superb value of " << Value() << "!" << std::endl; }
};


class Magnificant : public Superb
{
private:
    char ch;

public:
    Magnificant(int h = 0, char c = 'A') : Superb(h), ch(c) {}
    void Speak() const { std::cout << "I am a magnificent class!!!" << std::endl; }
    void Say() const { std::cout << "I hold the character " << ch 
                                 << " and the integer " << Value() << "!" << std::endl; }
};


#endif