//Copyright (c) 2022 user1687569
#include <iostream>
#include "cow.h"

int main()
{   
    Cow cow1;
    cow1.ShowCow();

    Cow cow2("Bull", "graze...", 68.9);
    cow2.ShowCow();

    Cow cow3 = cow2;
    cow3.ShowCow();
    
    return 0;
}



