//Copyright (c) 2022 user1687569
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>    // std::copy


void outint(int n)  { std::cout << n << " "; }

int main()
{
    std::list<int> one(5, 2);   // list of [2 2 2 2 2]
    
    int stuff[5] = {1, 2, 4, 8, 6};
    std::list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    
    int more[6] = {6, 4, 2, 4, 6, 5};
    std::list<int> three(two);
    three.insert(three.end(), more, more + 6);

    std::cout << "List one: ";
    // for_each(one.begin(), one.end(), outint);
    for(auto x : one) std::cout << x << " ";
    
    std::cout << std::endl << "List two: ";
    for_each(two.begin(), two.end(), outint);

    std::cout << std::endl << "List three: ";
    for_each(three.begin(), three.end(), outint);
    three.remove(2);

    std::cout << std::endl << "List three minus 2s: ";
    for_each(three.begin(), three.end(), outint);

    three.splice(three.begin(), one);   // after splice, one = 0
    std::cout << std::endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);   // 2 2 2 2 2 1 4 8 6 6 4 4 6 5
    std::cout << std::endl << "List one: ";
    for_each(one.begin(), one.end(), outint);
    std::cout << std::endl;

    // unique()只能将相邻的相同值压缩为单个值
    // 程序中仍包含不相邻的两个4和两个6
    three.unique();     // 2 1 4 8 6 4 6 5
    std::cout << std::endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);

    // 应用sort()后，再应用unique()时，每个值将只占一个位置
    three.sort();
    three.unique();     // 1 2 4 5 6 8
    std::cout << std::endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    two.f
    two.sort();
    three.merge(two);
    std::cout << std::endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);   // 1 1 2 2 4 4 5 6 6 8 8
    std::cout << std::endl;

    return 0;
}

