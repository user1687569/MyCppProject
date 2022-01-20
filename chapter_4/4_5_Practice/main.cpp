//Copyright (c) 2022 user1687569
#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    int calorie;
};



int main()
{
    CandyBar snack = {"Mocha Munch", 2.3, 350};

    std::cout << "Brand: " << snack.brand << std::endl;
    std::cout << "Weight: " << snack.weight << std::endl;
    std::cout << "calorie: " << snack.calorie << std::endl;
    return 0;
}




