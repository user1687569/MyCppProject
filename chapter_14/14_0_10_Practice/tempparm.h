//Copyright (c) 2022 user1687569
#ifndef _TEMPPARM_H_
#define _TEMPPARM_H_
#include <iostream>
#include "stacktp.h"

// 模板参数是 template < template <typename T> class Thing>
// 其中 template <typename T> class 是类型，Thing是参数

template < template <typename T> class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;

public:
    Crab() {};
    bool push(int a, double x) { return s1.push(a) && s2.push(x); }
    bool pop(int & a, double & x) { return s1.pop(a) && s2.pop(x); }
};


#endif