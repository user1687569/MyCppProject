//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstdlib>

// Abort()函数的原型位于头文件 cstdlib中
// 其典型实现是向标准错误流(即cerr使用的错误流)
// 发送消息abnornal program termination(程序异常终止), 然后终止程序

double hmean(double a, double b);


int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        z = hmean(x, y);
        std::cout << "Harmonic mean of " << x << " and " << y
                  << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }

    std::cout << "Bye!" << std::endl;    
    return 0;
}


double hmean(double a, double b)
{
    if(a == -b)
    {
        std::cout << "untenable arguments to hmean()" << std::endl;
        std::abort();
    }

    return 2.0 * a * b / (a + b);
}



