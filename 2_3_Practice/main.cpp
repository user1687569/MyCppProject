//Copyright (c) 2022 user1687569
#include <iostream>

void howManyMice();
void whatAreYouDoing();

int main()
{
    howManyMice();
    howManyMice();
    whatAreYouDoing();
    whatAreYouDoing();
    
    return 0;
}

void howManyMice()
{
    std::cout << "Three blind mice" << std::endl;
}

void whatAreYouDoing()
{
    std::cout << "See how they run" << std::endl;
}

