//Copyright (c) 2022 user1687569
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Lotto(int i, int j);

int main()
{
    const int TOT = 51, SELECT = 6;

    std::cout << "Play><y/n>";
    std::string choice;
    std::vector<int> res;

    while (std::cin >> choice && choice != "n")
    {
        res = Lotto(TOT, SELECT);
        for(auto it = res.begin(); it != res.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "Play again?<y/n>";
    }

    std::cout << "Bye~" << std::endl;
    return 0;
}


std::vector<int> Lotto(int total, int select)
{
    std::vector<int> all;
    for(int i = 1; i <= total; i++)
    {
        all.push_back(i);
    }

    random_shuffle(all.begin(), all.end());

    std::vector<int> rnd(all.begin(), all.begin() + select);

    return rnd;
}
