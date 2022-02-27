//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <map>
#include <algorithm>    // std::copy

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;


int main()
{
    using namespace std;
    MapCode codes;
    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkeley"));

    std::cout << "Number of cities with area code 415: "
              << codes.count(415) << std::endl;

    std::cout << "Number of cities with area code 415: "
              << codes.count(718) << std::endl;

    std::cout << "Number of cities with area code 510: "
              << codes.count(510) << std::endl;

    std::cout << "Area Code    City" << std::endl;
    MapCode::iterator it;
    for(it = codes.begin(); it != codes.end(); ++it)
        std::cout << "     " << (*it).first << "     "
                  << (*it).second << std::endl;
    
    std::pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
    std::cout << "Cities with area code 718: " << std::endl;
    for(it = range.first; it != range.second; ++it)
        std::cout << (*it).second << std::endl;

    return 0;
}

