//Copyright (c) 2022 user1687569
#ifndef _PAIRS_H_
#define _PAIRS_H_

#include <iostream>
#include <string>

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;

public:
    Pair() {}
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair(const Pair<T1, T2> & p);
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
};


template <typename T1, typename T2>
Pair<T1, T2>::Pair(const Pair<T1, T2> & p)
{
    a = p.a;
    b = p.b;
}


template<class T1, class T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}


template<class T1, class T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}


#endif
