//Copyright (c) 2022 user1687569
#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>

// 在祖先相同时，使用MI-Multiple inheritance必须引入虚基类
// 并修改构造函数初始化列表的规则
class Person
{
private:
    std::string firstname;
    std::string lastname;

protected:
    // 模块化方式
    virtual void Data() const;
    virtual void Get();

public:
    Person() : firstname("C"), lastname("++") {}
    Person(const std::string & f, const std::string & l) : firstname(f), lastname(l) {}
    virtual ~Person() = 0;  // pure virtual function
    
    virtual void Set() = 0;
    virtual void Show() const = 0;
};


// 使用虚基类
class Gunslinger : virtual public Person
{
private:
    double drawtime;
    int gunsNick;

protected:
    // 模块化方式
    void Data() const;
    void Get();

public:
    Gunslinger() : Person(), drawtime(0.0), gunsNick(0) {}
    Gunslinger(const std::string & f, const std::string & l, double d = 0.0, int g = 0) : Person(f, l), drawtime(d), gunsNick(g) {}
    Gunslinger(const Person &p, double d = 0.0, int g = 0) : Person(p), drawtime(d), gunsNick(g) {}
    
    virtual double Draw() const { return drawtime; }
    void Set();
    void Show() const;
};


// 虚基类
class PokerPlayer : virtual public Person
{
private:
    int cardNum;

protected:
    // 模块化方式
    void Data() const;
    void Get();

public:
    PokerPlayer() : Person(), cardNum(1) {}
    PokerPlayer(const std::string & f, const std::string & l, int c) : Person(f, l), cardNum(c) {}
    PokerPlayer(const Person &p, int c) : Person(p), cardNum(c) {}

    virtual double Draw() const { return cardNum; }
    void Set();
    void Show() const;
};


class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    void Data() const;
    void Get();

public:
    BadDude() {}

    BadDude(const std::string & f, const std::string & l, double d = 0.0, int g = 0, int c = 1)
        : Person(f, l), Gunslinger(f, l, d, g), PokerPlayer(f, l, c) {}

    BadDude(const Person & person, double d = 0.0, int g = 0, int c = 1)
        : Person(person), Gunslinger(person, d, g), PokerPlayer(person, c) {}
    
    BadDude(const Gunslinger & gunslinger, int c = 1)
        : Person(gunslinger), Gunslinger(gunslinger), PokerPlayer(gunslinger, c) {}
    
    BadDude(const PokerPlayer & portkerPlayer, double d = 0.0, int g = 0)
        : Person(portkerPlayer), Gunslinger(portkerPlayer, d, g), PokerPlayer(portkerPlayer) {}
    
    // 多重继承可能导致函数调用的二义性， 可使用模块化方式来化解
    void Set();
    void Show() const;
};


#endif
