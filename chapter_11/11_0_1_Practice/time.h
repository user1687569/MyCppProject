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
    // Time Sum(const Time & t) const;
    // 非成员版本的重载运算符函数所需的形参数目与运算符使用的操作数数目相同
    // 而成员版本所需的参数数目少一个，因为其中的一个操作数是被隐式地传递的调用对象
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const; 
    void Show() const;
    //乘法运算符需要两个操作数。
    //对于成员函数版本来说，一个操作数通过this指针隐式地传递，另一个操作数作为函数参数显式地传递
    //对于友元版本来说，两个操作数都作为参数来传递
    friend Time operator*(double m, const Time & t)
    { return t * m; }
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif