//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "stringbad.h"

int StringBad::num_strings = 0;


StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    std::cout << num_strings << ": \"" << str << "\" default object created" << std::endl;
}


StringBad::StringBad(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    std::cout << num_strings << ": \"" << str << "\" object created" << std::endl;
}


// 如果类中包含了使用new初始化的指针成员，应当定义一个复制函数，
// 以复制指向的数据，而不是指针，这被称为深度复制
// 复制的另一种形式（成员复制或浅复制）只是复制指针值
StringBad::StringBad(const StringBad & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    std::cout << num_strings << ": \"" << str << "\" object created" << std::endl;
}


StringBad::~StringBad()
{
    std::cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    std::cout << num_strings << " left" << std::endl;
    delete [] str;
}


StringBad & StringBad::operator=(const StringBad & st)
{
    if(this == &st)
        return *this;
    delete [] str;

    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
    return *this;
}


std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}


