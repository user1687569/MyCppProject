//Copyright (c) 2022 user1687569
#include <iostream>

void change(const int * pt, int n);

int main()
{
    int pop1 = 38383;
    const int pop2 = 2000;

    std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;
    change(&pop1, -103);    // 可以修改
    change(&pop2, -103);    // 不能修改
    std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;

    return 0;
}


void change(const int * pt, int n)
{
    int * pc;
    pc = const_cast<int *>(pt);
    *pc += n;
}


