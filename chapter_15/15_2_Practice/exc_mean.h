//Copyright (c) 2022 user1687569
#ifndef _EXC_MEAN_H_
#define _EXC_MEAN_H_
#include <iostream>
#include <stdexcept>

// 将对象用作异常类型

class bad_hmean : public std::logic_error
{
public:
    bad_hmean(const std::string & s = "hmean(): Invalid arguments a = -b\n") 
        : std::logic_error(s) {}
};



class bad_gmean : public std::logic_error
{
public:
    bad_gmean(const std::string & s = "gmean() argument should be >= 0\n") 
        : std::logic_error(s) {}
};





#endif