//Copyright (c) 2022 user1687569

//内联函数与宏有啥异同点?
//====相同====
两者都是可以加快程序运行效率，使代码变得更加通用
//====不同====
1. 内联函数的调用是传参，而宏定义只是简单的文本替换
2. 内联函数可以在程序运行时调用，宏定义是在程序编译时进行
3. 内联函数可以进行诸如类型安全检查、语句是否正确等编译功能，宏定义不具备这样的功能


//引用变量
引用是已定义的变量的别名，即另一个名称。
通过将引用变量用作参数，函数将使用原始数据，而不是其副本。


//引用和指针的区别
1. 表示法不同
2. 必须在声明引用时将其初始化，而不能像指针那样，先声明，再赋值。



//###############################################
//###############################################
//###############################################
//###############################################
//###############################################
//###############################################


//1 哪种函数适合定义为内联函数
1. 函数代码执行时间短
2. 该函数经常被调用
//只有一行代码的小型、非递归函数适合作为内联函数


//2 
a. void song(const char * name, int times = 1);
b. 函数定义不需要做任何修改，只有函数原型需要添加默认值的信息。
c. 可以为name提供默认值 "O. My Papa". 若要为name提供默认值，则必须先为times提供默认值。 //回答的真棒啊，哈哈哈哈哈
    void song(const char * name = "O. My Papa", int times = 1);


//3
void iquote(int n);
void iquote(double d);
void iquote(std::string str);
//######
void iquote(int n)
{
    std::cout << "\"" << n << "\"";
}
void iquote(double x)
{
    std::cout << '"' << x << '"';
}
void iquote(const char * str)
{
    std::cout << "\"" << str << "\"";
}


//4
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

//a
void showBox(const box & boxA)
{
    std::cout << "Show Box Info: " << std::endl;
    std::cout << "maker: " << boxA.maker << std::endl;
    std::cout << "height: " << boxA.height << std::endl;
    std::cout << "width: " << boxA.width << std::endl;
    std::cout << "length: " << boxA.length << std::endl;
    std::cout << "volume: " << boxA.volume << std::endl;
}

//b
void setVolume(box & boxA)
{
    boxA.volume = boxA.height * boxA.width * boxA.length;
}


//5
#include <iostream>
#include <array>
#include <string>
const int Seasons = 4;
const std::array<std::string, Seasons> Snames = 
    {"Spring", "Summer", "Fall", "Winter"};
void fill(std::array<double, Seasons> & pa);
void show(const std::array<double, Seasons> & da);
int main()
{
    std::array<double, Seasons> expenses;
    fill(expenses);
    show(expenses);
    return 0;
}
void fill(std::array<double, Seasons> & pa)
{
    for(int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa[i];
    }
}
void show(const std::array <double, Seasons> & da)
{
    double total = 0.0;
    std::cout << std::endl << "EXPENSES" << std::endl;
    for(int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << std::endl;
        total += da[i];
    }
    std::cout << "Total Expenses: $" << total << std::endl;
}


//6
a. 既可以使用默认参数，也可以使用函数重载
默认参数：
    double mass(double density, double volume = 1.0);
函数重载：
    double mass(double density);
    double mass(double density, double volume);

b. 只能使用函数重载。因为对于带参数列表的函数，
    必须从右向左添加默认值。
    void repeat(const std::string str);
    void repeat(int n, const std::string str);
    //#######
    void repeat(const char * str);
    void repeat(int times, const char * str);

c. 函数重载
    int average(int a, int b);
    double average(double a, double b);

d. 不能这样做，因为两个版本的特征标将相同。


//7
template<typename T>
T larger(T &a, T b)
{
    T t;
    t = a >= b ? a : b;
    return t;
}
//##########
template<typename T>
T max(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}


//8
struct box
{
    char  maker[40];
    float height;
    float width;
    float length;
    float volume;
};
template<typename T>
T larger(T &a, T &b);
template <> box larger<box>(box &boxA, box &boxB);
void showBox(const box & boxA);
void setVolume(box & boxA);
int main()
{
    int a = 1; 
    int b = 2;
    int nMax;
    nMax = larger(a, b);
    std::cout << "Max Integer value is: " << nMax << std::endl;

    double x = 2.0;
    double y = 3.0;
    double dMax;
    dMax = larger(x, y);
    std::cout << std::endl << "Max double value is: " << dMax << std::endl;

    box boxA = {"US", 20.0f, 30.0f, 40.0f};
    box boxB = {"China", 20.0f, 20.0f, 20.0f};
    setVolume(boxA);
    setVolume(boxB);
    box max;
    max = larger(boxA, boxB);
    std::cout << std::endl << "Max box is: " << std::endl;
    showBox(max);
    return 0;
}
void showBox(const box & boxA)
{
    std::cout << "maker: " << boxA.maker << std::endl;
    std::cout << "height: " << boxA.height << std::endl;
    std::cout << "width: " << boxA.width << std::endl;
    std::cout << "length: " << boxA.length << std::endl;
    std::cout << "volume: " << boxA.volume << std::endl;
}
void setVolume(box & boxA)
{
    boxA.volume = boxA.height * boxA.width * boxA.length;
}
template<typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}
template <> box larger<box>(box &boxA, box &boxB)
{
    return boxA.volume >= boxB.volume ? boxA : boxB;
}


//9
v1 -> float
v2 -> float &
v3 -> float &
v4 -> int
v5 -> double






