//Copyright (c) 2022 user1687569
#ifndef _ARRAYTP_H_
#define _ARRAYTP_H_
#include <iostream>
#include <cstdlib>

// 模板的具体化
// 1. 隐式实例化
//    ArrayTP<int, 100> stuff;  // implicit instantiation
// 2. 显式实例化
//    当使用关键字template并指出所需类型来声明类时，
//    编译器将生成类声明的显式实例化 explicit instantiation
//    声明必须位于模板定义所在的名称空间中
//    template class ArrayTP<std::string, 100>;
// 3. 显式具体化
//    template <> class Classname<specialized-type-name> {}
//    template <> class ArrayTP<std::string, int>l;
// 4. 部分具体化
//    template <class T1> class ArrayTP<T1, int> {};    //其中T1是没被具体化的类型参数


template <class T, int n>
class ArrayTP
{
private:
    T ar[n];

public:
    ArrayTP() {};
    explicit ArrayTP(const T & v);
    virtual T & operator[] (int i);
    virtual T operator[](int i) const;
};


template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T & v)
{
    for(int i = 0; i < n; i++)
        ar[i] = v;
}


template <class T, int n>
T & ArrayTP<T, n>::operator[](int i)
{
    if(i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i
                  << " is out of range" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return ar[i];
}


template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
    if(i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i 
                  << " is out of range" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return ar[i];
}


#endif
