//Copyright (c) 2022 user1687569
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>    // std::copy

template<class T>
class TooBig
{
private:
    T cutoff;

public:
    TooBig(const T &t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; }
};

void outint(int n) { std::cout << n << " "; }

int main()
{
    TooBig<int> f100(100);
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    std::list<int> yadayada(vals, vals + 10);
    std::list<int> etcetera(vals, vals + 10);

    std::cout << "Original lists: " << std::endl;
    for_each(yadayada.begin(), yadayada.end(), outint);
    std::cout << std::endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    std::cout << std::endl;

    yadayada.remove_if(f100);               // 函数符 f100是一个声明的对象
    etcetera.remove_if(TooBig<int>(200));   // 另一个函数符 TooBig<int>(200) 是一个匿名对象，它是由构造函数调用创建的
    
    std::cout << "Trimmed lists: " << std::endl;
    for_each(yadayada.begin(), yadayada.end(), outint);
    std::cout << std::endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    std::cout << std::endl;

    bool bo = TooBig<int>(10)(15);
    bool bo2 = TooBig<int>(10)(9);
    std::cout << "bo = " << bo << std::endl;
    std::cout << "bo2 = " << bo2 << std::endl;

    return 0;
}

