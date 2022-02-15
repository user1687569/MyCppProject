//Copyright (c) 2022 user1687569
#include <iostream>
#include "stoneweight.h"

StoneWeight::StoneWeight()
{
    stone = pounds = pounds_left = 0;
    mode = STONE_FORM;
}


StoneWeight::StoneWeight(double lbs, Mode form)
{
    stone = int (lbs) / LBS_PER_STONE;
    pounds_left = int (lbs) % LBS_PER_STONE + lbs - int (lbs);
    pounds = lbs;
    mode = form;
}


StoneWeight::StoneWeight(int stn, double lbs, Mode form)
{
    stone = stn;
    pounds_left = lbs;
    pounds = stn * LBS_PER_STONE + lbs;
    mode = form;
}


StoneWeight::~StoneWeight()
{
}


void StoneWeight::stone_mode()
{
    mode = STONE_FORM;
}


void StoneWeight::int_pounds_mode()
{
    mode = INT_POUNDS_FORM;
}


void StoneWeight::float_pounds_mode()
{
    mode = FLOAT_POUNDS_FORM;
}


StoneWeight::operator int() const
{
    return int (pounds + 0.5);
}


StoneWeight::operator double() const
{
    return pounds;
}


StoneWeight StoneWeight::operator+(const StoneWeight & st) const
{
    StoneWeight result;
    result = pounds + st.pounds;
    return result;
}


StoneWeight StoneWeight::operator-(const StoneWeight & st) const
{
    StoneWeight result;
    result = pounds - st.pounds;
    return result;
}


StoneWeight StoneWeight::operator*(double n) const
{
    StoneWeight result;
    result = pounds * n;
    return result;
}


bool StoneWeight::operator<(const StoneWeight & st) const
{
    return pounds < st.pounds;
}


bool StoneWeight::operator>(const StoneWeight & st) const
{
    return pounds > st.pounds;
}


bool StoneWeight::operator<=(const StoneWeight & st) const
{
    return pounds <= st.pounds;
}


bool StoneWeight::operator>=(const StoneWeight & st) const
{
    return pounds >= st.pounds;
}


bool StoneWeight::operator==(const StoneWeight & st) const
{
    return pounds == st.pounds;
}


bool StoneWeight::operator!=(const StoneWeight & st) const
{
    return pounds != st.pounds;
}


std::ostream & operator<<(std::ostream & os, const StoneWeight & st)
{
    if(st.mode == StoneWeight::STONE_FORM)
    {
        os << st.stone << " stone, " << st.pounds_left << " pounds" << std::endl;
    }
    else if(st.mode == StoneWeight::INT_POUNDS_FORM)
    {
        os << int (st.pounds + 0.5)  << " pounds" << std::endl;
    }
    else if(st.mode == StoneWeight::FLOAT_POUNDS_FORM)
    {
        os << st.pounds << " pounds" << std::endl;
    }
    else
        os << "StoneWeight object mode is invalid!" << std::endl;

    return os;
}


