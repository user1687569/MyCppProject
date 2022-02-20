//Copyright (c) 2022 user1687569
#ifndef _TEMP2TEMP_H_
#define _TEMP2TEMP_H_
#include <iostream>


// 模板类的非约束模板友元函数
// 前一节中的约束模板友元函数是在类外面声明的模板的具体化
// 通过在类内部声明模板，可以创建非约束友元函数
// 即每个函数具体化都是每个类具体化的友元

template <typename T> 
class ManyFriend
{
private:
    T item;

public:
    ManyFriend(const T & i) : item(i) {}
    
    template <typename C, typename D>
    friend void show2(C &, D &);
};


template <typename C, typename D> 
void show2(C &c, D & d)
{
    std::cout << c.item << ", " << d.item << std::endl;
}


#endif