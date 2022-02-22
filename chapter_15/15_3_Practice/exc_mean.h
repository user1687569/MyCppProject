//Copyright (c) 2022 user1687569
#ifndef _EXC_MEAN_H_
#define _EXC_MEAN_H_
#include <iostream>
#include <stdexcept>

// 将对象用作异常类型

class bad_base : public std::logic_error
{
private:
    double v1;
    double v2;

public:
    bad_base(double a = 0, double b = 0, const std::string & s = "what(): error in base object\n") 
        : v1(a), v2(b), std::logic_error(s) {}
    virtual void mesg();
};


inline void bad_base::mesg()
{
    std::cout << v1 << ", " << v2 << " " << "invalid arguments";
}


class bad_hmean : public bad_base
{
private:
    double v1;
    double v2;

public:
    bad_hmean(double a = 0, double b = 0, const std::string & s = "what(): error in bad_hmean object\n") 
        : bad_base(a, b, s) {}
    void mesg();
};


inline void bad_hmean::mesg()
{
    std::cout << "hmean("
              << v1
              << ", "
              << v2
              << "): "
              << "invalid arguments: a = -b"
              << std::endl;
}


class bad_gmean : public bad_base
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0, const std::string & s = "what(): error in bad_gmean object\n") 
        : bad_base(a, b, s) {}
    void mesg();
};


inline void bad_gmean::mesg()
{
    std::cout << "gmean() arguments should be >= 0\n";
}


#endif