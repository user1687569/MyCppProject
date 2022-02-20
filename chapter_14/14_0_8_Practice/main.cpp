//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include "pairs.h"


int main()
{
    Pair<std::string, int> ratings[4] = 
    {
        Pair<std::string, int>("The Purpled Duck", 5),
        Pair<std::string, int>("Jaquie's Frisco Al Fresco", 4),
        Pair<std::string, int>("Cafe Souffle", 5),
        Pair<std::string, int>("Bertie's Eats", 3)
    };

    int joints = sizeof(ratings) / sizeof(Pair<std::string, int>);
    std::cout << "Rating:\t Eatery" << std::endl;
    for(int i = 0; i < joints; i++)
        std::cout << ratings[i].second() << ":\t "
                  << ratings[i].first() << std::endl;
    std::cout << "Oops! Revised rating: " << std::endl;
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;
    std::cout << ratings[3].second() << ":\t "
              << ratings[3].first() << std::endl;

    return 0;
}


