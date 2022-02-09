//Copyright (c) 2022 user1687569
#include <iostream>

void print(const char * str);
void print(const char * str, int count);

int main()
{
    print("Apple");
    print("HuaWei", 5);
    return 0;
}


void print(const char * str)
{
    std::cout << str << std::endl;
}


void print(const char * str, int count)
{
    for(int i = 0; i < count; i++)
    {
        std::cout << str << std::endl;
    }
}

