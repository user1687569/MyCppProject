//Copyright (c) 2022 user1687569
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;
    ArrayDb scores;
    std::ostream & arr_out(std::ostream & os) const;

public:
    Student() : name("Null Student"), scores() {}

    // 使用explicit的原因
    // 可以用一个参数调用的构造函数将用作从参数类型到类类型的隐式转换函数，在这个地方会出现错误
    // 因此使用explicit关闭隐式转换
    explicit Student(const std::string & s) : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}
    Student(const std::string & s, int n) : name(s), scores(n) {}
    Student(const std::string & s, const ArrayDb & a) : name(s), scores(a) {}
    Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {}
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