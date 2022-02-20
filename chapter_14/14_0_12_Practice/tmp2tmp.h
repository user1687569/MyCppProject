//Copyright (c) 2022 user1687569
#ifndef _TEMP2TEMP_H_
#define _TEMP2TEMP_H_
#include <iostream>


// 模板类的约束模板友元函数


// 可以修改前一个示例，使友元函数本身成为模板
// 具体地说，为约束模板友元作准备，
// 要使类地每一个具体化都获得与友元匹配的具体化


// 声明: 将每个友元函数声明为模板函数
template <typename T> void counts();
template <typename T> void report(T &);


template <typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;

public:
    HasFriendT(const TT & i) : item(i) { ct++; }
    ~HasFriendT() { ct--; }

    // 在函数中再次将模板声明为友元
    // 声明中的<>指出这是模板具体化
    // 对于report(), <>可以为空，因为可以从函数参数推断出如下模板类型参数  HasFriendT<TT>
    // 但counts()函数没有参数，因此必须使用模板参数语法 <TT>来知名其具体化
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT> &);
};


template <typename T>
int HasFriendT<T>::ct = 0;


template <typename T>
void counts()
{
    std::cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    std::cout << "template counts(): " << HasFriendT<T>::ct << std::endl;
}


template <typename T>
void report(T & hf)
{
    std::cout << hf.item << std::endl;
}


#endif