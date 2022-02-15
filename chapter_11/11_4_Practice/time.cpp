//Copyright (c) 2022 user1687569
#include <iostream>
#include "time.h"


Time::Time()
{
    hours = minutes = 0;
}


Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}


void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}


void Time::AddHour(int h)
{
    hours += h;
}


void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}


void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes" << std::endl;
}


Time operator+(const Time & t1, const Time & t2)
{
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}


Time operator-(const Time & t1, const Time & t2)
{
    Time diff;
    int total1, total2;
    total1 = t1.minutes + t1.hours * 60;
    total2 = t2.minutes + t2.hours * 60;

    diff.minutes = (total1 - total2) % 60;
    diff.hours = (total1 - total2) / 60;
    return diff;
}


Time operator*(double m, const Time & t)
{
    Time result;
    long totalminutes = t.hours * m * 60 + t.minutes * m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}


// 最常见的运算符重载任务之一是定义 << 运算符， 使之可与cout一起使用，来显示对象的内容
// 要让ostream对象成为第一个操作数，需要将运算符函数定义为友元
// 要使重新定义的运算符能与其自身拼接，需要将返回类型声明为 ostream &
// 调用 cout << xxx 应使用cout对象本身，而不是它的拷贝，
// 因此该函数按引用（而不是按值）来传递该对象
std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes" << std::endl;
    return os;
}





