//Copyright (c) 2022 user1687569
#include <iostream>
#include "stoneweight.h"

StoneWeight::StoneWeight()
{
    stone = pounds = pounds_left = 0;
}


StoneWeight::StoneWeight(double lbs)
{
    stone = int (lbs) / LBS_PER_STONE;
    pounds_left = int (lbs) % LBS_PER_STONE + lbs - int (lbs);
    pounds = lbs;
}


StoneWeight::StoneWeight(int stn, double lbs)
{
    stone = stn;
    pounds_left = lbs;
    pounds = stn * LBS_PER_STONE + lbs;
}


StoneWeight::~StoneWeight()
{
}


// show weight in stones
void StoneWeight::show_stone() const
{
    std::cout << stone << " stone, " << pounds_left << " pounds" << std::endl;
}


// show weight in pounds
void StoneWeight::show_lbs() const
{
    std::cout << pounds << " pounds" << std::endl;
}


StoneWeight::operator int() const
{
    return int (pounds + 0.5);
}


StoneWeight::operator double() const
{
    return pounds;
}


StoneWeight StoneWeight::operator*(double n) const
{
    StoneWeight result;
    result = pounds * n;
    return result;
}


// StoneWeight operator*(double n, const StoneWeight & st)
// {
//     StoneWeight result;
//     result = st.pounds * n;
//     return result;
// }



