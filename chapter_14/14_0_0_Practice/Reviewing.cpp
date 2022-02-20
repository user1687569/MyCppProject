//Copyright (c) 2022 user1687569


// 私有继承 和 保护继承之间的异同点
相同点：基类的接口在派生类中也是可用的，但在继承曾自结构之外是不可用的
不同点：使用私有继承时，第三代类将不能使用基类的接口，
       这是因为基类的公有方法在派生类中将变成私有方法；
       使用保护继承时，基类的公有方法在第二代中将变成受保护的，
       因此第三代派生类可以使用它们。


// 虚基类
虚基类使得从多个类(它们的基类相同)派生出的对象只继承一个基类对象。
在虚函数与虚基类之间并不存在明显的联系


#include <array>
#include <string>
// 模板别名
typedef std::array<double, 12> arrd;
typedef std::array<int, 12> arri;
typedef std::array<std::string, 12> arrst;
arrd gallons;
arri days;
arrst months;


template<typename T>
    using arrtype = std::array<T, 12>;

arrtype<double> gallons;
arrtype<int> days;
arrtype<std::string> months;



// 1. 以A栏的类为基类时，B栏的类采用公有派生还是私有派生更合适？
----------------------------------------------------------------------------
A                               | B                         |
----------------------------------------------------------------------------
class Bear                      | class PolarBear           | 私有，北极熊是一种熊
class Kitch                     | class Home                | 私有，家里有厨房
class Person                    | class Programmer          | 公有，程序员是一种人
class Person                    | class HorseAndJockey      | 私有，马和驯马师的组合中包含一个人
class Person, class Automobile  | class Driver              | 人是公有的，因为司机是一个人；汽车是私有的，因为司机有一辆汽车


// 2
Frabjous::Frabjous(const char * s)
{
    strcpy(fab, s);
}
Gloam::Gloam(int g, const char * s) : glip(g), fb(s) {}
Gloam::Gloam(int g, const Frabjous & f) : glip(g), fb(f) {}
void Gloam::tell()
{
    fb.tell();
    std::cout << glip << std::endl;
}

// 3
Frabjous::Frabjous(const char * s)
{
    strcpy(fab, s);
}
Gloam::Gloam(int g, const char * s) : glip(g), Frabjous(s) {}
Gloam::Gloam(int g, const Frabjous & f) : glip(g), Frabjous(f) {}
void Gloam::tell()
{
    Frabjous::tell();
    std::cout << glip << std::endl;
}


// 4
class Stack<Worker *>
{
private:
    enum {MAX = 10};
    Worker * items[MAX];
    int top;

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Worker * & item);
    bool pop(Worker * & item);    
}


// 5
程序清单 14.18生成4个模板
ArrayTP<int, 10>
ArrayTP<double, 10>
ArrayTP<int, 5>
ArrayTP< ArrayTP <int, 5>, 10>


ArrayTP<std::string> sa;
StackTP< ArrayTP<double> > stack_array_db;
ArrayTP< StackTP<Worker *> > array_stack_worker;


// 指出虚基类和非虚基类之间的区别
非虚基类：如果两条继承路线有相同的祖先，则类中将包含祖先成员的两个拷贝
虚基类：使用虚基类可以解决这种问题，类中只包含祖先成员的一个拷贝






