//Copyright (c) 2022 user1687569
#ifndef _STONEWEIGHT_H_
#define _STONEWEIGHT_H_


class StoneWeight
{
private:
    static const int LBS_PER_STONE = 14;
    int stone;          // 英石
    double pounds_left;
    double pounds;      // 磅

public:
    StoneWeight();
    // 只有一个参数的类构造函数用于将类型与该参数相同的值转换为类类型
    StoneWeight(double lbs);

    // 在构造函数声明中使用explicit可防止隐式转换，而只允许显式转换
    // explicit StoneWeight(double lbs);
    StoneWeight(int stone, double lbs);
    ~StoneWeight();

    void show_lbs() const;
    void show_stone() const;

    //转换函数必须是类方法
    //转换函数不能指定返回类型
    //转换函数不能有参数
    operator int() const;
    operator double() const;

    StoneWeight operator*(double n) const;
    friend StoneWeight operator*(double n, const StoneWeight & st)
    { return st * n; }
};


#endif


