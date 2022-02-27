//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <algorithm>


int main()
{
    std::string letters;
    std::cout << "Enter the letter grouping (quit to quit): ";
    while (std::cin >> letters && letters != "quit")
    {
        std::cout << "Permutations of " << letters << std::endl;
        sort(letters.begin(), letters.end());
        std::cout << letters << std::endl;
        // permutation: 置换，排列
        while (next_permutation(letters.begin(), letters.end()))
            std::cout << letters << std::endl;
        std::cout << "Enter next sequence (quit to quit): ";
    }

    std::cout << "Done." << std::endl;
    return 0;
}

