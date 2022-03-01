//Copyright (c) 2022 user1687569
#include <iostream>
#include <initializer_list>
#include <algorithm>


template <typename T>
T average_list(std::initializer_list<T> it)
{
    T sum;
    for(auto item = it.begin(); item != it.end(); item++)
    {
        sum += *item;
    }

    return sum / it.size();
}


int main()
{
    // list of double deduced from list contents
    auto q = average_list({15.4, 10.7, 9.0});
    std::cout << q << std::endl;

    // list of int deduced from list contents
    std::cout << average_list({20, 30, 19, 17, 45, 38}) << std::endl;

    // forced list of double
    auto ad = average_list<double>({'A', 70, 65.33});
    std::cout << ad << std::endl;

    return 0;
}


