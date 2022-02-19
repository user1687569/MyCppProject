//Copyright (c) 2022 user1687569
#ifndef _STRINGBAD_H_
#define _STRINGBAD_H_
#include <iostream>

class StringBad
{
private:
    char * str;
    int len;
    static int num_strings;

public:
    StringBad();
    StringBad(const char * s);
    StringBad(const StringBad &);   // 复制构造函数
    ~StringBad();

    StringBad & operator=(const StringBad & st);

    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif