//Copyright (c) 2022 user1687569
#include <iostream>
#include "move.h"


int main()
{
    Move one;
    one.showmove();

    Move two(1.0, 2.0);
    two.showmove();

    Move three(2.0, 2.0);
    Move four;
    
    four = three.add(two);
    four.showmove();

    four.reset(9.0, 9.0);
    four.showmove();

    return 0;
}



