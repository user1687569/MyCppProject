//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "string.h"

int String::num_strings = 0;


String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}


String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}


// 如果类中包含了使用new初始化的指针成员，应当定义一个复制函数，
// 以复制指向的数据，而不是指针，这被称为深度复制
// 复制的另一种形式（成员复制或浅复制）只是复制指针值
String::String(const String & st)
{
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings++;
}


String::~String()
{
    --num_strings;
    delete [] str;
}


String & String::operator=(const String & st)
{
    if(this == &st)
        return *this;
    //释放str指向的内存，并为新字符串分配足够的内存
    delete [] str;

    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
    return *this;
}


String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}


bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}


bool operator>(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) > 0);
    // or
    // return st2 < st1;
}


bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}


char & String::operator[](int i)
{
    return str[i];
}


const char & String::operator[](int i) const
{
    return str[i];
}


std::ostream & operator<<(std::ostream & os, const String & st)
{
    os << st.str;
    return os;
}


std::istream & operator>>(std::istream & is, String & st)
{
    char temp[String::CINLIMIT];
    is.get(temp, String::CINLIMIT);
    if(is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    
    return is;
}


int String::HowMany()
{
    return num_strings;
}

