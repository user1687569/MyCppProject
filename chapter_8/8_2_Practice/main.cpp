//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cstring>

struct CandyBar
{
    char brand[20];
    double weight;
    int heat;
};

void setMember(CandyBar &candy, const char * str);
void setMember(CandyBar &candy, const double weight);
void setMember(CandyBar &candy, const int heat);
void showCandyBar(CandyBar &candy);

int main()
{   
    CandyBar candy;

    setMember(candy, "Millennium");
    setMember(candy, 2.85);
    setMember(candy, 350);

    showCandyBar(candy);

    return 0;
}

void setMember(CandyBar &candy, const char * str)
{
    strcpy(candy.brand, str);
}

void setMember(CandyBar &candy, const double weight)
{
    candy.weight = weight;
}

void setMember(CandyBar &candy, const int heat)
{
    candy.heat = heat;
}

void showCandyBar(CandyBar &candy)
{
    std::cout << "Candy Brand: " << candy.brand << std::endl;
    std::cout << "Weight: " << candy.weight << std::endl;
    std::cout << "Heat: " << candy.heat << std::endl;
}
