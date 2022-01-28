//Copyright (c) 2022 user1687569
#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main()
{
    double totalOne, choicesOne;
    double totalTwo, choicesTwo;

    std::cout << "Enter the total number of choices on the game card and "
                 "the number of picks allowed: " << std::endl;
    while((std::cin >> totalOne >> choicesOne >> totalTwo >> choicesTwo) 
            && choicesOne <= totalOne
            && choicesTwo <= totalTwo)
    {
        std::cout << "You have one chance in ";
        std::cout << (probability(totalOne, choicesOne) * probability(totalTwo, choicesTwo));
        std::cout << " of winning." << std::endl;
        std::cout << "Next four numbers(q to quit): ";
    }

    std::cout << "bye" << std::endl;
    return 0;
}


long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;

    for(n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;

    return result;
}


