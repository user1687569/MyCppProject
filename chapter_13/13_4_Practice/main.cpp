//Copyright (c) 2022 user1687569
#include <iostream>
#include "port.h"

// 第二个任务是解释为什么有的方法重新定义了，而有些没有重新定义
// 答: 由于有些方法在派生类中需要添加更多的功能，而有些方法只需承担基类中的功能

// 第三个任务是解释为何没有将operator=()和operator<<() 声明为虚方法
// 答: 因为基类Port与派生类VintagePort中的operator=() 和 operator<<()
//     中所包含的参数不一样，而虚函数要求派生类和基类的方法名和参数列表相同


int main()
{
    Port portOne("Gallo", "tawny", 20);
    portOne.Show();
    std::cout << portOne;

    Port portTwo;
    portTwo = portOne;
    std::cout << std::endl << std::endl;
    portTwo.Show();
    std::cout << portTwo;

    VintagePort vintagePortOne("Benz", "Cool", 25, "Car", 1900);
    std::cout << std::endl << std::endl;
    vintagePortOne.Show();
    std::cout << vintagePortOne;

    VintagePort vintagePortTwo;
    vintagePortTwo = vintagePortOne;
    std::cout << std::endl << std::endl;
    vintagePortTwo.Show();
    std::cout << vintagePortTwo;

    return 0;
}




