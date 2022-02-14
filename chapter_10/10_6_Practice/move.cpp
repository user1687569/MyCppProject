//Copyright (c) 2022 user1687569
#include <iostream>
#include "move.h"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}


void Move::showmove() const
{
    std::cout << "Coordinate x:" << x << " y:" << y << std::endl;
}


// discards qualifiers: 丢弃限定符，当尝试修改const类型时，会报discards qualifiers
// -fpermissive: 将有关不合格代码的某些诊断从错误降级为警告

// double Move::getX() const
// {
//     return x;
// }

// double Move::getY() const
// {   
//     return y;
// }


Move Move::add(const Move & m) const
{   
    Move newCoordinate;
    // newCoordinate.x =  x + m.getX();
    // newCoordinate.y =  y + m.getY();
    newCoordinate.x =  x + m.x;
    newCoordinate.y =  y + m.y;

    return newCoordinate;
}


void Move::reset(double a, double b)
{
    x = a;
    y = b;
}


