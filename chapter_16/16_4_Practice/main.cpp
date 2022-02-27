//Copyright (c) 2022 user1687569
#include <iostream>
#include <set>
#include <algorithm>

template <class T>
int reduce(T ar[], int n);

int main()
{
    int count;
    long longArray[] = {1, 5, 3, 6, 7, 2 , 33 , 453 ,32, 7, 7, 7, 88};
    count = reduce(longArray, 13);
    std::cout << "count of longArray = " << count << std::endl;
    return 0;
}


template <class T>
int reduce(T ar[], int n)
{
    std::sort(ar, ar + n);
    auto past_end = std::unique(ar, ar + n);

    return past_end - ar;
}

