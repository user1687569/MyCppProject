//Copyright (c) 2022 user1687569
#include <iostream>
#include <initializer_list>
#include <algorithm>


template <typename T>
T sum_value(std::initializer_list<T> it)
{
    T sum = 0;
    for(auto item = it.begin(); item != it.end(); item++)
    {
        sum += *item;
    }

    return sum;
}


int main()
{
    auto q = sum_value({15.4, 10.7, 9.0});
    std::cout << q << std::endl;

    std::cout << sum_value({20, 30, 19, 17, 45, 38}) << std::endl;
    
    auto ad = sum_value({70, 67, 98, 78});
    std::cout << ad << std::endl;

    return 0;
}


