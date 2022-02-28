//Copyright (c) 2022 user1687569
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

void show(std::string & s) { std::cout << s << " "; }

int main()
{
    std::vector<std::string> matFriends, patFriends;
    std::vector<std::string> all;
    std::string name;

    std::ifstream fmat("mat.dat", std::ios_base::in);
    std::ifstream fpat("pat.dat", std::ios_base::in);
    if(!fmat.is_open() || !fmat.is_open())
    {
        // std::cerr << "Can't open " << argv[1] << "or " << argv[2] << "for input" << std::endl;
        std::cerr << "Can't open input file!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ofstream fout("all.dat", std::ios_base::out);
    if(!fout.is_open())
    {
        // std::cerr << "Can't open " << argv[3] << "for output" << std::endl;
        std::cerr << "Can't open output file!" << std::endl;
        exit(EXIT_FAILURE);
    }

    
    // std::cout << "Mat! Enter your friends(Enter stop to stop): ";
    // while (std::getline(std::cin, name) && name != "stop")
    while(fmat >> name)
    {
        matFriends.push_back(name);
        // std::cout << "Another name: ";
    }

    // std::cout << "Pat! Enter your friends(stop to stop): ";
    // while (std::getline(std::cin, name) && name != "stop")
    while(fpat >> name)
    {
        patFriends.push_back(name);
        // std::cout << "Another name: ";
    }
    
    std::sort(matFriends.begin(), matFriends.end());
    std::sort(patFriends.begin(), patFriends.end());

    std::cout << "Mat's friends: " << std::endl;
    for_each(matFriends.begin(), matFriends.end(), show);
    std::cout << "Pat's friends: " << std::endl;
    for_each(patFriends.begin(), patFriends.end(), show);

    // merge to vectors
    std::vector<std::string> allFriends;
    allFriends.reserve(matFriends.size() + patFriends.size());
    allFriends.insert(allFriends.end(), matFriends.begin(), matFriends.end());
    allFriends.insert(allFriends.end(), patFriends.begin(), patFriends.end());

    std::sort(allFriends.begin(), allFriends.end());
    auto new_end = std::unique(allFriends.begin(), allFriends.end());
    std::cout << "All friends: " << std::endl;
    for_each(allFriends.begin(), new_end, show);
    std::cout << std::endl;

    return 0;
}