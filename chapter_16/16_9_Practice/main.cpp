//Copyright (c) 2022 user1687569
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <random>
#include <algorithm>

const int SIZE = 1000000;

int main()
{
    std::vector<int> vi0(SIZE, 0);
    for(int i = 0; i < SIZE; i++)
        vi0.at(i) = rand();
    
    std::vector<int> vi(vi0);
    std::list<int> li(SIZE, 0);
    std::copy(vi0.begin(), vi0.end(), li.begin());

    clock_t start = std::clock();
    std::sort(vi.begin(), vi.end());
    clock_t end = std::clock();
    std::cout << "sort vector time: "
              << (double)(end - start)/CLOCKS_PER_SEC << std::endl;
    
    start = std::clock();
    li.sort();
    end = clock();
    std::cout << "sort list time: "
              << (double)(end - start)/CLOCKS_PER_SEC << std::endl;
    
    std::copy(vi0.begin(), vi0.end(), li.begin());
    start = std::clock();
    std::copy(li.begin(), li.end(), vi.begin());
    std::sort(vi.begin(), vi.end());
    std::copy(vi.begin(), vi.end(), li.begin());
    end = std::clock();

    std::cout << "copy+sort+copy time: "
              << (double)(end - start)/CLOCKS_PER_SEC << std::endl;

    return 0;
}

