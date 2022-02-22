//Copyright (c) 2022 user1687569
#include <iostream>
#include <cmath>
#include <string>
#include "exc_mean.h"

// 栈解退


class demo
{
private:
    std::string word;

public:
    demo(const std::string & str)
    {
        word = str;
        std::cout << "demo " << word << " created"<< std::endl;
    }

    // 演示了异常极其重要的一点: 程序进行栈解退以回到能够捕获异常的地方时，
    // 将释放栈中的自动存储变量。如果变量是类对象，将为该对象调用析构函数
    ~demo()
    {
        std::cout << "demo " << word << " destroyed" << std::endl;
    }

    void show() const
    {
        std::cout << "demo " << word << " lives!" << std::endl;
    }
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);


int main()
{
    double x, y, z;
    {
        demo d1("found in block in main()");
        std::cout << "Enter two numbers: ";
        while (std::cin >> x >> y)
        {
            try{                    
                z = means(x, y);
                std::cout << "The mean of " << x << " and " << y
                          << " is " << z << std::endl;
                std::cout << "Enter next set of numbers <q to quit>: ";
            }
            catch (bad_hmean & bh)    
            {
                bh.mesg();
                std::cout << "Try again." << std::endl;
                continue;
            }
            catch (bad_gmean & bg)
            {
                std::cout << bg.mesg();
                std::cout << "Values used: " << bg.v1 << ", "
                          << bg.v2 << std::endl;
                std::cout << "Sorry, you don't get to play any more." << std::endl;
                break;
            }
        }
        d1.show();      // demo found in block in main() lives!
    }
    
    std::cout << "Bye!" << std::endl;    
    std::cin.get();
    std::cin.get();
    return 0;
}


double hmean(double a, double b)
{
    if(a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}


double gmean(double a, double b)
{
    if(a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}


// template one
double means(double a, double b)
{
    double am, hm, gm;
    demo d2("found in means()");

    am = (a + b) / 2.0;
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch(bad_hmean & bh)
    {
        bh.mesg();
        std::cout << "Caught in hmean()" << std::endl;
        throw;      // rethrows the exception
    }
    catch(bad_gmean & bg)
    {
        bg.mesg();
        std::cout << "Caught in gmean()" << std::endl;
        throw;      // rethrows the exception
    }

    d2.show();      // demo found in means() lives!
    return (am + hm + gm) / 3.0;
}



// template two
// 6和-8被发送到函数means()
// means() 创建一个新的demo对象，将6 和 -8 传递给 hmean(),
// 后者(hmean) 在处理它们时没有出现问题
// 然而, means()将 6 和 -8 传递给 gmean(),
// 后者(gmean) 异常
// 由于means() 不能捕获 bad_gmean异常，因此异常被传递给main(), 同时不再执行 means()中的其他代码
double means(double a, double b)
{
    double am, hm, gm;
    demo d2("found in means()");

    am = (a + b) / 2.0;
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch(bad_hmean & bh)
    {
        bh.mesg();
        std::cout << "Caught in means()" << std::endl;
        throw;      // rethrows the exception
    }

    d2.show();      // demo found in means() lives!
    return (am + hm + gm) / 3.0;
}




