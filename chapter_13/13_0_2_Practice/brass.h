//Copyright (c) 2022 user1687569
#ifndef _BRASS_H_
#define _BRASS_H_
#include <iostream>
#include <string>

class Brass
{
private:
    std::string fullname;
    long accountNum;
    double balance;

public:
    Brass(const std::string & s = "Nullbody",
          long an = -1,
          double bal = 0.0);
    void Deposit(double amt);
    double Balance() const;

    // 如果要在派生类中重新定义基类的方法，通常应将基类方法声明为虚的
    // 这样，程序将根据对象类型而不是引用或指针的类型来选择方法版本
    // 为基类声明一个虚析构函数也是一种惯例，确保在释放派生对象时，按正确的顺序调用析构函数
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    virtual ~Brass() {}

};


class BrassPlus : public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string & s = "Nullbody",
              long an = -1,
              double bal = 0.0,
              double ml = 500,
              double r = 0.11125);
    BrassPlus(const Brass & ba,
              double ml = 500,
              double r = 0.11125);
    
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};


#endif