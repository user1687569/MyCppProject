//Copyright (c) 2022 user1687569
#ifndef _TEMPMEMB_H_
#define _TEMPMEMB_H_
#include <iostream>

// template <typename T>
// class Beta
// {
// private:
//     template <typename V>
//     class hold
//     {
//     private:
//         V val;
//     public:
//         hold(V v = 0) : val(v) {}
//         void show() const { std::cout << val << std::endl; }
//         V Value() const { return val; } 
//     };

//     hold<T> q;
//     hold<int> n;

// public:
//     Beta(T t, int i) : q(t), n(i) {}
    
//     template<typename U>
//     U Blab(U u, T t) { return (n.Value() + q.Value()) * u / t; } 
//     void Show() const { q.show();   n.show(); }
// };


template <typename T>
class Beta
{
private:
    template <typename V>
    class hold;
    hold<T> q;
    hold<int> n;

public:
    Beta(T t, int i) : q(t), n(i) {}
    
    template<typename U>
    U Blab(U u, T t);
    void Show() const { q.show();   n.show(); }
};


//  member definition 
template <typename T>
    template <typename V>
    class Beta<T>::hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { std::cout << val << std::endl; }
        V Value() const { return val; } 
    };


// member definition
template <typename T>
    template<typename U>
    U Beta<T>::Blab(U u, T t)
    {
        return (n.Value() + q.Value()) * u / t;
    }


#endif
