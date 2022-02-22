//Copyright (c) 2022 user1687569
#include <iostream>
#include <typeinfo>
#include "rtti2.h"

Grand * GetOne();

int main()
{
    std::srand(std::time(0));
    Grand * pg;
    Superb * ps;

    for(int i = 0; i < 25; i++)
    {
        pg = GetOne();
        // type_info类的实现随厂商而异，但包含一个name()成员，
        // 该函数返回一个随实现而异的字符串: 通常(但并非一定)是类的名称
        std::cout << "Now processing type " << typeid(*pg).name() << "." << std::endl;
        pg->Speak();
        if(ps = dynamic_cast<Superb *>(pg))
        {
            ps->Say();
        }

        // type_info类重载了 == 和 != 运算符，以便可以使用这些运算符来对类型进行比较
        // 如果pg指向的是一个Magnificent对象，则下述表达式的结果为 bool值[true], 否则为[false]
        // 如果pg是一个空指针，程序将引发bad_typeid异常，该异常类型是从exception类派生而来的
        if(typeid(Magnificant) == typeid(*pg))
            std::cout << "Yes, you're really magnificent." << std::endl;
        
        std::cout << std::endl;
    }

    return 0;
}


Grand * GetOne()
{
    Grand * p;
    switch (std::rand() % 3)
    {
    case 0:
        p = new Grand(std::rand() % 100);
        break;
    case 1:
        p = new Superb(std::rand() % 100);
        break;
    case 2:
        p = new Magnificant(std::rand() % 100,
                    'A' + std::rand() % 26);
        break;
    default:
        break;
    }

    return p;
}


