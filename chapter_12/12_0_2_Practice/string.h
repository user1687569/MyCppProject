//Copyright (c) 2022 user1687569
#ifndef _STRING_H_
#define _STRING_H_
#include <iostream>

class String
{
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIMIT = 80;

public:
    String();
    String(const char * s);
    String(const String &);   // 复制构造函数
    ~String();

    int length() const { return len; }
    String & operator=(const String & st);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;

    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend std::ostream & operator<<(std::ostream & os, const String & st);
    friend std::istream & operator>>(std::istream & is, String & st);

    // 不能通过对象调用静态成员函数
    static int HowMany();
};

#endif