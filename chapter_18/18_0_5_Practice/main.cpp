//Copyright (c) 2022 user1687569
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size = 390000L;

int main()
{
    std::vector<int> numbers(Size);
    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);
    std::cout << "Sample size = " << Size << std::endl;

    int count3 = std::count_if(numbers.begin(), numbers.end(), 
            [](int x) { return x % 3 == 0; } );
    std::cout << "Count of numbers divisible by 3: " << count3 << std::endl;
    
    int count13 = std::count_if(numbers.begin(), numbers.end(), 
            [](int x) { return x % 13 == 0; } );
    std::cout << "Count of numbers divisible by 13: " << count13 << std::endl << std::endl;

//     count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(), 
            [&](int x) { count3 += x % 3 == 0; count13 += x % 13 == 0; } );
    std::cout << "Count of numbers divisible by 3: " << count3 << std::endl;
    std::cout << "Count of numbers divisible by 13: " << count13 << std::endl << std::endl;

    return 0;
}

