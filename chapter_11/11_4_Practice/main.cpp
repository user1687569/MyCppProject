//Copyright (c) 2022 user1687569
#include <iostream>
#include "time.h"

int main()
{
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    std::cout << "Planning time = ";
    // planning.Show();
    std::cout << planning;

    std::cout << "Coding time = ";
    // coding.Show();
    std::cout << coding;

    std::cout << "Fixing time = ";
    // fixing.Show();
    std::cout << fixing;

    // total = coding.Sum(fixing);
    // std::cout << "coding.Sum(fixing) = ";
    total = coding + fixing;
    std::cout << "coding + fixing = ";
    // total.Show();
    std::cout << total;

    Time doing(1, 10);
    Time diff;
    diff = total - doing;
    std::cout << "total - doing = ";
    // diff.Show();
    std::cout << diff;

    Time adjusted;
    adjusted = 1.8 * total;
    std::cout << "1.8 * total = ";
    // adjusted.Show();
    std::cout << adjusted;

    Time adjusted2;
    adjusted2 = 0.5 * total;
    std::cout << "0.5 * total = ";
    std::cout << adjusted2;

    return 0;
}



