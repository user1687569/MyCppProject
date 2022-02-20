//Copyright (c) 2022 user1687569
#ifndef _FRIENDTEMP_H_
#define _FRIENDTEMP_H_
#include <iostream>

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;

public:
    HasFriend(const T & i) : item(i) { ct++; }
    ~HasFriend() { ct--; }
    // counts() 函数是友元函数，不是通过对象调用的，也没有对象参数
    // 那么它是如何访问HasFriend对象呢？
    // 1. 可以访问全局对象
    // 2. 可以使用全局指针访问非全局对象
    // 3. 可以创建自己的对象
    // 4. 可以访问独立于对象的模板类的静态数据成员
    friend void counts();
    // 对模板类中的友元函数，要提供模板类参数，必须指明具体化
    friend void reports(HasFriend<T> &);
};


// 每个具体实例化都有它自己的静态数据 ct
template <typename T>
int HasFriend<T>::ct = 0;


void counts()
{
    std::cout << "int count: " << HasFriend<int>::ct << "; ";
    std::cout << "double count: " << HasFriend<double>::ct << std::endl;
}

// reports()本身并不是模板函数，而只是使用一个模板作参数
// 意味着必须为要使用的友元定义显式具体化
void reports(HasFriend<int> & hf)
{
    std::cout << "HasFriend<int>: " << hf.item << std::endl;
}


void reports(HasFriend<double> & hf)
{
    std::cout << "HasFriend<double>: " << hf.item << std::endl;
}

#endif