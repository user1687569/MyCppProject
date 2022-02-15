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


//不要返回指向局部变量或临时对象的引用
//函数执行完毕后，局部变量和临时对象将消失，引用将指向不存在的数据
// Time Time::Sum(const Time & t) const
// {
//     Time sum;
//     sum.minutes = minutes + t.minutes;
//     sum.hours = hours + t.hours + sum.minutes / 60;
//     sum.minutes %= 60;
//     return sum;
// }

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}


Time Time::operator-(const Time & t) const
{
    Time diff;
    int total1, total2;
    total1 = t.minutes + 60 * t.hours;
    total2 = minutes + 60 * hours;
    
    diff.minutes = (total2 - total1) % 60;
    diff.hours = (total2 - total1) / 60;
    return diff;
}


Time Time::operator*(double n) const
{
    Time result;
    long totalminutes = hours * n * 60 + minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}


// void Time::Show() const
// {
//     std::cout << hours << " hours, " << minutes << " minutes" << std::endl;
// }

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


