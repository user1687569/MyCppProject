//Copyright (c) 2022 user1687569
#ifndef _WINE_H_
#define _WINE_H_
#include <iostream>
#include <string>
#include <valarray>
#include "pairs.h"


class Wine : private std::string, private Pair< std::valarray<int>, std::valarray<int> >
{
private:
    typedef std::valarray<int> ArrayInt; 
    typedef Pair<ArrayInt, ArrayInt> PairArray;
    int yearCount;

public:
    Wine();
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);
    Wine(const Wine & w);
    ~Wine();

    void GetBottles();
    std::string & Label();
    void Show();
    int sum();
};


#endif