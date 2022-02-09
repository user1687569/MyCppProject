//Copyright (c) 2022 user1687569
#include <iostream>
#include <limits>

template<typename T>
T max5(T t[]);


int main()
{
    int nList[] = {1, 3, 5, 7, 9};
    double dList[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int nMax = INT16_MIN;
    double dMax = INT64_MIN;

    nMax = max5(nList);
    std::cout << "Max integer is: " << nMax << std::endl;

    dMax = max5(dList);
    std::cout << "Max double value is: " << dMax << std::endl;

    return 0;
}


template<typename T>
T max5(T t[])
{
    T max;
    max = t[0] >= t[1] ? t[0] : t[1];
    max = max >= t[2] ? max : t[2];
    max = max >= t[3] ? max : t[3];
    max = max >= t[4] ? max : t[4];
    max = max >= t[5] ? max : t[5];

    return max;
}

