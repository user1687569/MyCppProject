//Copyright (c) 2022 user1687569
#ifndef _TIME_H_
#define _TIME_H_


class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHour(int h);
    void Reset(int h = 0, int m = 0);
    void Show() const;

    //乘法运算符需要两个操作数。
    //对于成员函数版本来说，一个操作数通过this指针隐式地传递，另一个操作数作为函数参数显式地传递
    //对于友元版本来说，两个操作数都作为参数来传递
    friend Time operator+(const Time & t1, const Time & t2);
    friend Time operator-(const Time & t1, const Time & t2);
    friend Time operator*(double m, const Time & t);
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif