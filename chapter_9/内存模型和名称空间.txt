//Copyright (c) 2022 user1687569

//1 对于下面的情况，应使用哪种存储方案
a. homer是函数的形参 -> 自动存储 (homer将自动成为自动变量)
b. secret变量由两个文件共享 ->具有外部链接性的静态存储 
    (应该在一个文件中将secret定义为外部变量，
    并在第二个文件中使用extern来声明它)
c. topsecret变量由一个文件中的所有函数共享，
    但对于其他文件来说是隐藏的 -> 具有内部链接性的静态存储
    (可以在外部定义前加上关键字static,将topsecret定义为
    一个具有内部链接的静态变量。也可在一个未命名的名称
    空间中进行定义)
d. beencalled记录包含它的函数被调用的次数 -> 无链接性的静态存储
    (应在函数中的声明前加上关键字static,将beencalled
    定义为一个本地静态变量)

//2 using声明和using编译指令之间有何区别？
using声明使特定的标识符可用
using编译指令使整个名称空间可用


//3 不使用using声明和using编译指令
#include <iostream>
int main()
{
    double x;
    std::cout << "Enter value: ";
    while (!(std::cin >> x))
    {
        std::cout << "Bad input. Please enter a number: ";
        std::cin.clear();
        while(std::cin.get() != '\n')
            continue;
    }
    std::cout << "Value = " << x << std::endl;
    return 0;
}


//4 使用using声明，而不是using编译指令
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    double x;
    cout << "Enter value: ";
    while(!(cin >> x))
    {
        cout << "Bad input. Please enter a number: ";
        cin.clear();
        while (cin.get() != '\n')
            continue;
    }
    cout << "Value = " << x << endl;
    return 0;
}


//5
//###### calculate.cpp
#include <iostream>
double average(int a, int b)
{
    return (a + b) / 2.0;
}
//###### main.cpp
#include <iostream>
extern double average(int, int);
int main()
{
    int a = 5;
    int b = 6;
    double avg;
    avg = average(a, b);
    std::cout << "Average value is: " << avg << std::endl;
    return 0;
}

//6
10
4
0
Other: 10, 1
another(): 10, -4


//7
1
4, 1, 2
2
2
4, 1, 2
2













