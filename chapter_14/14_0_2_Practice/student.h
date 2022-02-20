//Copyright (c) 2022 user1687569
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>
#include <valarray>

// 包含和私有继承的第一个主要区别
// 新的student类不需要私有数据，因为两个基类已经提供了所需的所有数据成员
// 包含版本提供了两个被显式命名的对象成员，而私有继承提供了两个无名称的子对象成员

class Student : private std::string, private std::valarray<double>
{
private:
    typedef std::valarray<double> ArrayDb;
    // std::string name;
    // ArrayDb scores;
    std::ostream & arr_out(std::ostream & os) const;

public:
    // 包含和私有继承的第二个主要区别
    // 对于继承类，新版本的构造函数将使用成员初始化列表语法，它使用类名而不是成员名来标识构造函数
    Student() : std::string("Null Student"), ArrayDb() {}

    // 使用explicit的原因
    // 可以用一个参数调用的构造函数将用作从参数类型到类类型的隐式转换函数，在这个地方会出现错误
    // 因此使用explicit关闭隐式转换
    explicit Student(const std::string & s) : std::string(s), ArrayDb() {}
    explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
    Student(const std::string & s, int n) : std::string(s), ArrayDb(n) {}
    Student(const std::string & s, const ArrayDb & a) : std::string(s), ArrayDb(a) {}
    Student(const char * str, const double * pd, int n) : std::string(str), ArrayDb(pd, n) {}
    ~Student();

    double Average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);
    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};


#endif