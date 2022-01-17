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
    CandyBar snacks[2] = 
                    {
                        {"Mocha Munch", 2.3, 350},
                        {"Spicy strip", 1.8, 380}
                    };

    std::cout << "First type snack: " << std::endl;
    std::cout << "Brand: " << snacks[0].brand << std::endl;
    std::cout << "Weight: " << snacks[0].weight << std::endl;
    std::cout << "calorie: " << snacks[0].calorie << std::endl;
    
    std::cout << std::endl;
    std::cout << "Second type snack: " << std::endl;
    std::cout << "Brand: " << snacks[1].brand << std::endl;
    std::cout << "Weight: " << snacks[1].weight << std::endl;
    std::cout << "calorie: " << snacks[1].calorie << std::endl;
    return 0;
}




