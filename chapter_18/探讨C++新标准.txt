//Copyright (c) 2022 user1687569
#include <iostream>

----------------------------------------------------------
探讨C++新标准
----------------------------------------------------------
复习前面介绍过的C++11功能
----------------------------------------------------------
新类型
C++11新增了 long long 和 unsigned long long, 以支持64位的整型；
新增了类型 char16_t 和 char32_t，以支持16位和32位的字符表示；
还新增了“原始”字符串


----------------------------------------------------------
统一的初始化
C++11扩大了用大括号括起的列表(初始化列表)的使用范围，使其可用于所有的
内置类型和用户定义的类型(即类对象)。
使用初始化列表时，可添加等号(=)，也可不添加：
int x = {5};
double y {2.75};
short quar[5] {4, 5, 2, 76, 1};

如果类有将模板std::initializer_list作为参数的构造函数，
则只有该构造函数可以使用列表初始化形式

1. 缩窄
初始化列表语法可防止缩窄，即禁止将数值赋给无法存储它的数值变量。

常规初始化允许程序员执行可能没有意义的操作：
char c1 = 1.57e27;      // ok
char c2 = 459585821;    // ok

然而，
char c1 {1.57e27};      // not ok
char c2 = {459585821};  // not ok

2. std::initializer_list
C++11提供了模板类 initializer_list，可将其用作构造函数的参数。
如果类有接受initializer_list作为参数的构造函数，则初始化列表语法
就智能用于该构造函数。列表中的元素必须是同一种类型或可转换为同一种类型
initializer_list包含成员函数 begin() 和 end(),可用于获悉列表的范围


----------------------------------------------------------
声明
1. auto
以前，关键字auto是一个存储类型说明符
C++11将其用于实现自动类型推断，这要求进行显式初始化，
让编译器能够将变量的类型设置为初始值的类型

auto maton = 112;
auto pt = &maton;
double fm(double, int);
auto pf = fm;

关键字auto还可简化模板声明。
例如，
for(std::initializer_list<double>::iterator p = il.begin(); p != il.end(); p++)
替换为
for(auto p = il.begin(); p != il.end(); p++)


2. decltype
关键字decltype将变量的类型声明为表达式指定的类型。

double x;
int n;
decltype(x * n) q;
decltype(&x) pd;

3. 返回类型后置
C++11新增了一种函数声明语法：
在函数名和参数列表后面(而不是前面)指定返回类型：
double f1(double, int);
auto f2(double, int) -> double;

就常规函数的可读性而言，这种语法好像是倒退，
但让您能够使用decltype来指定模板函数的返回类型：
template<typename T, typename U>
auto eff(T t, U u) -> decltype(T*U)
{
    ...
}


4. 模板别名： using =
对于冗长或复杂的标识符，如果能够创建其别名将很方便。
C++为此提供了typedef:
typedef std::vector<std::string>::iterator itType;

C++提供了另一种创建别名的语法：
using itType = std::vector<std::string>::iterator;

差别在于，新语法也可用于模板部分具体化，但typedef不能：
template<typename T>
    using arr12 = std::array<T, 12>;

对于下述声明：
std::array<double, 12> a1;
std::array<std::string, 12> a2;
可替换为：
arr12<double> a1;
arr12<std::string> a2;


5. nullptr
空指针是不会指向有效数据的指针。
C++在源码中使用0表示这种指针，但内部表示可能不同。
0即可以表示指针常量，又可表示整型常量。

C++11新增了关键字 nullptr, 用于表示空指针；
它是指针类型，不能转换为整型类型。


----------------------------------------------------------
智能指针
如果在程序中使用new从堆(自由存储区)分配内存，等到不再需要时，
应使用delete将其释放。
C++引入了智能指针auto_ptr，以帮助自动完成这个过程。

auto_ptr;
unique_ptr;
shared_ptr;
weak_ptr;


----------------------------------------------------------
异常规范方面的修改

标准委员会认为，指出函数不会引发异常有一定的价值，
它们谓词添加了关键字noexcept:
void f875(short, short) noexcept;   // doesn't throw an exception


----------------------------------------------------------
作用域内枚举
enum Old1 {yes, no, maybe};
enum class New1 {never, sometimes, often, always};
enum struct New2 {never, lever, sever};



----------------------------------------------------------
对类的修改

1. 显式转换运算符
C++很早就支持对象自动转换，但人们逐渐意识到，
自动类型转换可能导致意外转换的问题。
为解决这种问题，C++引入了关键字explicit，
以禁止单参数构造函数导致的自动转换：

2. 类内成员初始化


----------------------------------------------------------
模板和STL方面的修改
1. 基于范围的for循环
double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
for(double x : prices)
    std::cout << x << std::endl;

2. 新的STL容器
C++11新增了STL容器 forward_list, unordered_map,
unordered_multimap, unordered_set 和 unordered_multiset

容器 forward_list是一种单向链表，只能沿一个方向遍历；
与双向链接的list容器相比，它更简单，在占用存储空间方面更经济。

C++还新增了模板 array.

3. 新的STL方法
C++11新增了STL方法 cbegin() 和 cend()


4. valarray升级
C++11添加了两个函数(begin() 和 end())，它们都接受valarray作为参数，
并返回迭代器，这些迭代器分别指向valarray对象的第一个元素和最后一个元素后面。


5. 摒弃export


6. 尖括号
为比避免与运算符>>混淆，C++要求在声明嵌套模板时使用空格将尖括号分开：
std::vector<std::list<int> > vl;
C++不再这样要求：
std::vector<std::list<int>> vl;

----------------------------------------------------------
右值引用
传统的C++引用(现在称为左值引用)使得标识符关联到左值。
左值是一个表示数据的表达式(如变量名或解除引用的指针)，程序可获取其地址。

C++11新增了右值引用，这是使用&&表示的。右值引用可以关联到右值，
即可出现在赋值表达式右边，但不能对其应用地址运算符的值。
右值包括字面常量，诸如 x + y等表达式以及返回值的函数。
int x = 10;
int y = 23;
int && r1 = 13;
int && r2 = x + y;
double && r3 = std::sqrt(2.0);

注意，r2关联到的是当前计算 x + y得到的结果。
也就是说，r2关联到的是23，即使以后修改了x或y，也不会影响到r2。

有趣的是，将右值关联到右值引用导致该右值被存储到特定的位置，
且可以获取该位置的地址。
也就是说，虽然不能将运算符&用于13，但可将其用于r1。
通过将数据与特定的地址关联，使得可以通过右值引用来访问该数据。

引用右值引用的主要目的之一是实现移动语义

----------------------------------------------------------
移动语义和右值引用

为何需要移动语义
先来看C++之前的复制过程，假设有如下代码：
vector<string> vstr;
// build up a vector of 20,000 strings, each of 1000 characters
...
vector<string> vstr_copy1(vstr);

vector 和 string类都使用动态内存分配，
因此它们必须定义使用某种new版本的复制构造函数。

为初始化对象vstr_copy1,复制构造函数 vector<string>将使用
new给 20000个 string对象分配内存，而每个string对象又将调用
string的复制构造函数，该构造函数使用new为1000个字符分配内存。
接下来，全部20000000个字符都将从 vstr控制的内存中复制到
vstr_copy1控制的内存中。

例如，假设有一个函数，它返回一个 vector<string>对象;
vector<string> allcaps(const vector<string> & vs);
{
    vector<string> temp;
    return temp;
}

vector<string> vstr;
vector<string> vstr_copy1(vstr);
vector<string> vstr_copy2(allcaps(vstr));

实际文件还留在原来的地方，而只是修改记录。
这种方法被称为移动语义(move semantics)

强制移动
std::move();

----------------------------------------------------------
新的类功能

特殊成员函数
在原有4个特殊成员函数(默认构造函数、复制构造函数、复制赋值运算符
和析构函数)的基础上，C++新增了两个：
移动构造函数和移动赋值运算符

如果你没有提供赋值构造函数，而代码又需要它，编译器将提供一个默认的复制构造函数；
如果你没有提供移动构造函数，而代码又需要它，编译器将提供一个默认的移动构造函数；
Someclass::Someclass(const Someclass &);
Someclass::Someclass(Someclass &&);

最后，如果你没有提供析构函数，编译器将提供一个。

----------------------------------------------------------
默认的方法和禁用的方法

C++11让你能够更好地控制要使用的方法。
假定你要使用某个默认的函数，而这个函数由于某种原因不会自动创建。
例如，你提供了移动构造函数，因此编译器不会自动创建默认的构造函数、
复制构造函数和复制赋值构造函数。
在这些情况下，你可使用关键字default显式地声明这些方法地默认版本：

class Someclass
{
public:
    Someclass(Someclass &&);
    Someclass() = default;
    Someclass(const Someclass &) = default;
    Someclass & operator=(const Someclass &) = default;
    ...
};

另一方面，关键字delete可用于禁止编译器使用特定方法。
例如，
要禁止复制对象，可禁用复制构造函数和复制赋值运算符：
class Someclass
{
public:
    // use compiler-generated default constructor
    Someclass() = default;

    // disable copy constructor and copy assignment operator:
    Someclass(const Someclass &) = delete;
    Someclass & operator=(const Someclass & ) = delete;

    // use compiler-generated move constructor and move assignment operator
    Someclass(Someclass &&) = default;
    Someclass & operator=(Someclass &&) = default;
    
    Someclass & operator+(const Someclass &) const;
    ...
};

Someclass one;
Someclass two;
Someclass three(one);       // not allowed, one 是 左值
Someclass four(one + two);  // allowed, 表达式是右值


第12章说过，要禁止复制，可将复制构造函数和赋值运算符放在类定义的private部分，
但使用delete也能达到这个目的，且更不容易犯错，更容易理解。


关键字default只能用于6个特殊成员函数，但delete可用于任何成员函数。
delete的一种可能用法是禁止特定的转换。


----------------------------------------------------------
委托构造函数
如果给类提供了多个构造函数，你可能重复编写相同的代码。
也就是说，有些构造函数可能需要包含其他构造函数中已有的代码。
为让编码工作更简单、更可靠，C++允许你在一个构造函数的定义中使用
另一个构造函数。
这被称为委托，因为构造函数暂时将创建对象的工作委托给另一个构造函数。

class Notes
{
    int k;
    double x;
    std::string st;
public:
    Notes();
    Notes(int);
    Notes(int, double);
    Notes(int, double, std::string);
};

Notes:Notes(int kk, double xx, std::string stt)
    : k(kk), x(xx), st(stt) {}

Notes::Notes() : Notes(0, 0.01, "Oh") {}

Notes::Notes(int kk) : Notes(kk, 0.01, "Ah") {}

Notes::Notes(int kk, double xx) : Notes(kk, xx, "Uh") {}


----------------------------------------------------------
继承构造函数
为进一步简化编码工作，C++11提供了一种让派生类能够继承基类构造函数的机制。
C++98提供了一种让名称空间中函数可用的语法：
namespace Box
{
    int fn(int) { ... }
    int fn(double) { ... }
    int fn(const char *) { ... }
}
using Box::fn;
这让函数fn的所有重载版本都可用。
也可使用这种方法让基类的所有非特殊成员函数对派生类可用。

class C1
{
    ...
public:
    int fn(int j) { ... }
    double fn(double w) { ... }
    void fn(const char * s) { ... }
};

class C2 : public C1
{
    ...
public:
    using C1::fn;
    double fn(double) { ... };
};

...
C2 c2;
int k = c2.fn(3);       // use C1::fn(int)
double z = c2.fn(2.4);  // use C2::fn(double)

C2中的using声明让C2对象可使用C1的三个fn()方法，但将选择C2而不是C1定义的
方法fn(double).

C++11将这种方法用于构造函数。
这让派生类继承基类的所有构造函数(默认构造函数、复制构造函数
和移动构造函数除外)，但不会使用与派生类构造函数的特征标匹配的构造函数。


----------------------------------------------------------
管理虚方法：override 和 final
虚方法对实现多态类层次结构很重要，让基类引用或指针能够根据指向的
对象类型调用相应的方法，但虚方法也带来了一些编程陷阱。
例如，假设基类声明了一个虚方法，而你决定在派生类中提供不同的版本，
这将覆盖旧版本。
如果特征标不匹配，将隐藏而不是覆盖旧版本：
class Action
{
    int a;
public:
    Action(int i = 0) : a(i) {}
    int val() const { return a; }
    virtual void f(char ch) const { std::cout << val() << ch << "\n"; }
};

class Bingo : public Action
{
public:
    Bingo(int i = 0) : Action(i) {}
    virtual void f(char * ch) const { std::cout << val() << ch << "!\n"; }
};

在C++11中，可使用虚说明符 override指出你要覆盖一个虚函数：
将其放在参数列表后面。如果声明与基类方法不匹配，编译器将视为错误。
因此，下面的Bingo::f()版本将生成一条编译错误消息：

virtual void f(char * ch) const override { std::cout << val() << ch << "!\n"; }

['virtual void Bingo::f(char*) const' marked 'override', but does not override
virtual void f(char * ch) const override]

说明符 final解决了另一个问题。
你可能像禁止派生类覆盖特定的虚方法，为此可在参数列表后面加上final。
例如，下面的代码禁止Action的派生类重新定义函数f();

virtual void f(char ch) const final { std::cout << val() << ch << "\n"; }

说明符override和final并非关键字，而是具有特殊含义的标识符。
这意味着编译器根据上下文确定它们是否有特殊含义；
在其他上下文中，可将它们用作常规标识符，如变量名或枚举。


----------------------------------------------------------
Lambda函数

[&count](int x) { count += (x % 13 == 0)}

比较函数指针、函数符和Lambda函数
假设你要生成一个随机整数列表，并判断其中多少个整数可被3整除，
多少个整数可被13整除。
----------------------------------------------------------
函数指针
使用vector<int>存储数字，并使用STL算法 generate()在其中填充随机数：
#include <vector>
#include <algorithm>
#include <cmath>
...
std::vector<int> numbers(1000);
std::generate(vector.begin(), vector.end(), std::rand);

函数generate()接受一个区间(由前两个参数指定)，并将每个元素设置为
第三个参数返回的值，而第三个参数是一个不接受任何参数的函数对象。
在上述示例中，该函数对象是一个指向标准函数rand()的指针。

通过使用算法count_if()，很容易计算出有多少个元素可被3整除。
与函数generate()一样，前两个参数应指定区间，而第三个参数应是一个
返回true或false的函数对象。函数count_if()计算这样的元素数，即它
使得指定的函数对象返回true。
为判断元素能否被3整除，可使用下面的函数定义：
bool f3(int x) { return x % 3 == 0; }
同样，为判断元素能否被13整除，可使用下面的函数定义：
bool f13(int x) { return x % 13 == 0; }

定义上述函数后，便可计算复合条件的元素数了，如下所示：
int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
std::cout << "Count of numbers divisible by 3: " << count3 << '\n';

int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
std::cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

----------------------------------------------------------
函数符
函数符是一个类对象，并能只能像函数名那样使用它，
这要归功于类方法operator()()。
就这个示例而言，函数符的优点之一是，可使用同一个函数符来完成
这两项计数任务。
class f_mod
{
private:
    int dv;

public:
    f_mod(int d = 1) : dv(d) {}
    bool operator()(int x) { return x % dv == 0; }
};
这为何可行呢？因为可使用构造函数创建存储特定整数值的f_mod对象：
f_mod obj(3);
而这个对象可使用方法operator()来返回一个bool值：
bool is_div_by_3 = obj(7);  // same as obj.operator()(7)

构造函数本身可用作诸如count_if()等函数的参数：
count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));

----------------------------------------------------------
最后来看使用lambda的情况
名称lambda来自lambda calculus, 一种定义和应用函数的数学系统。
这个系统让你能够使用匿名函数-即无需给函数命名。
在C++11中，对于接受函数指针或函数符的函数，
可使用匿名函数定义(lambda)作为其参数。

与前述函数f3()对应的lambda如下：
[](int x) { return x % 3 == 0; }
这与f3()的函数定义很像：
// bool f3(int x) { return x % 3 == 0; }
bool f3(int x) { return x % 3 == 0; }

差别有两个：
1. 使用[]替代了函数名(这就是匿名的又来)
2. 没有声明返回类型

返回类型相当于使用decltype根据返回值推断得到的，这里为bool.
就这个示例而言，你将以如下方式使用该lambda:
count3 = std::count_if(numbers.begin(), numbers.end(),
            [](int x) { return x % 3 == 0; } );

也就是说，使用整个lambda表达式替换函数指针或函数符构造函数。

仅当lambda表达式完全由一条返回语句组成时，自动类型推断才管用；
否则，需要使用新增的返回类型后置语法：
[](double x) -> double { int y = x; return x - y; } // return type is double



----------------------------------------------------------
为何使用lambda?
距离, 简洁, 效率和功能.


----------------------------------------------------------
最后，lambda有一些额外的功能。
具体地说，lambda可访问作用域内的任何动态变量；
要捕获要使用的变量，可将其名称放在中括号内。

如果只指定了变量名，如[z]，将按值访问变量；

如果在名称前加上&，如[&count]，将按引用访问变量。

[&]让你能够按引用访问所有动态变量

[=]让你能够按值访问所有动态变量

还可以混合使用这两种方式，
例如，
[ted, &ed]让你能够按值访问ted 以及 按引用访问ed

[&, ted]让你能够按值访问ted 以及 按引用访问其他所有动态变量

[=, &ed]让你能够按引用访问ed以及按值访问其他所有动态变量

可将下述代码：
int count13;
...
count13 = std::count_if(numbers.begin(), numbers.end()
                [](int x) { return x % 13 == 0; } );
替换为：
int count13 = 0;
std::for_each(numbers.begin(), numbers.end(),
    [&count13](int x) {count13 += x % 13 == 0; });

[&count13]让lambda能够在其代码中使用count13。
由于count13是按引用捕获的，因此在lambda对count13所做的任何修改
都将影响原始count13.

通过这种技术，可使用一个lambda表达式计算可被3整除的元素数和
可被13整除的元素数：
int count3 = 0;
int count13 = 0;
std::for_each(numbers.begin(), numbers.end(),
    [&](int x) { count3 += x % 3 == 0; count13 += x % 13 == 0; });


----------------------------------------------------------
包装器
C++提供了多个包装器, wrapper, 也叫适配器[adapter].
这些对象用于给其他编程接口提供更一致或更合适的接口。

bind1st 和 bind2ed, 它们让接受两个参数的函数能够与这样的STL算法匹配，
即它要求将接受一个参数的函数作为参数。

C++11提供了其他的包装器，包括模板bind, men_fn和reference_wrapper
以及包装器 function.
bind可替代bind1st 和 bind2ed，但更灵活；
mem_fn让你能够将成员函数作为常规函数进行传递
reference_wrapper让你能够创建行为像引用但可被复制的对象
包装器function让你能够以统一的方式处理多种类似于函数的形式

----------------------------------------------------------
下面更详细地介绍包装器function及其解决的问题

包装器function及模板的低效性
请看下面的代码：
answer = ef(q);

ef是什么呢？它可以是函数名、函数指针、函数对象或有名称的lambda表达式。
所有这些都是可调用的类型(callable type).

----------------------------------------------------------
18.5.2 修复问题

调用特征标是有返回类型以及用括号括起来并用头号分隔的参数类型列表定义的，
因此use_f()的调用特征标都是 double(double)

模板function是在头文件functional中声明的，
它从调用特征标的角度定义了一个对象，
可用于包装调用特征标相同的函数指针、函数对象或lambda表达式

下面的声明创建一个名为fdci的function队形，
它接受一个char参数和一个int参数，并返回一个double值:
std::function<double(char, int)> fdci;
然后，可以将接受一个char参数和一个int参数，
并返回一个double值得任何函数指针、函数对象或lambda表达式赋给它。

----------------------------------------------------------
18.5.3 其他方式
typedef function<double(double)> fdd;
cout << use_f(y, fdd(dub)) << std::endl;
cout << use_f(y, fdd(square)) << std::endl;
...


其次，程序清单让use_f()的第二个实参与形参f匹配，
但另一种方法是让形参f的类型与原始实参匹配。
为此，将第二个参数声明为function包装器对象，如下所示：

#include <functional>
template <typename T>
T use_f(T v, std::function<T(T)> f)
{
    static int count = 0;
    count++;
    std::cout << "   use_f count = " << count
              << ", &count = " << &count << std::endl;

    return f(v);
}

这样，函数的调用将如下：
std::cout << "  " << use_f<double>(y, dub) << std::endl;
std::cout << "  " << use_f<double>(y, Fp(5.0)) << std::endl;


----------------------------------------------------------
18.6 可变参数模板 variadic template
可变参数模板让你能够创建这样的模板函数和模板类，
即可接受可变数量的参数

要创建可变参数模板，需要理解几个要点：
模板参数包 parameter pack
函数参数包
展开参数包 unpack
递归

----------------------------------------------------------
18.6.1 模板和函数参数包
C++11提供了一个用省略号表示的元运算符(meta-operator),
让你能够声明表示模板参数包的标识符，
模板参数包基本上是一个类型列表。

同样，它还让你能够声明表示函数参数包的标识符，
而函数参数包基本上是一个值列表。其语法如下：
template<typename... Args>
void show_list1(Args... args)
{
    ...
}
其中，Args是一个模板参数包，而args是一个函数参数包。
Args 和 T 的差别在于，T与一种类型匹配，而Args与任意数量(包括零)
的类型匹配。请看下面的函数调用：
show_list1('S', 80, "sweet", 4.5);

----------------------------------------------------------
18.6.2 展开参数包
但函数如何访问这些包的内容呢？
索引功能在这里不适用，即你不能使用 Args[2]来访问包中的第三个类型。
相反，可将省略号放在函数参数包名的右边，将参数包展开。
例如，请看下述有缺陷的代码：
template<typename... Args>
void show_list1(Args... args)
{
    show_list1(args...);
}

有可能导致无限递归

----------------------------------------------------------
18.6.3 在可变参数模板函数中使用递归
正确使用递归为访问参数包的内容提供了解决方案。
这里的核心理念是，将函数参数包展开，对列表中的第一项进行处理，
在将余下的内容传递给递归调用，以此类推，直到列表为空。
与常规递归一样，确保递归将终止很重要。
这里的技巧是将模板头改为如下所示：
template<typename T, typename... Args>
void show_list3(T value, Args... args)
{
    std::cout << value << ", ";
    show_list3(args...);
}


----------------------------------------------------------
18.7 C++11新增的其他功能
----------------------------------------------------------
18.7.1 并行编程
当前，为提高计算机性能，增加处理器数量比提高处理器速度更容易。

有些操作能受益于多线程，但有些不能。
考虑单向链表的搜索：程序必须从链表开头开始，沿链表依次向下搜索，
直到到达链表末尾；在这种情况下，多线程的帮助不大。

再来看未经排序的数组。考虑到数组的随机存取特征，可让一个线程从数组开头
开始搜索，并让另一个线程从数组中间开始搜索，这将让搜索时间减半。

多线程确实带来了很多问题。如果一个线程挂起或两个线程试图同时访问
同一项数据，结果将如何呢？
为解决并行性问题，C++定义了一个支持线程化执行的内存模型，添加了
关键字thread_local,提供了相关的库支持。
关键字thread_local将变量声明为静态存储，其持续性与特定线程相关；
即定义这种变量的线程过期时，变量也将过期。

库支持由 原子操作库 和 线程支持库 组成，其中原子操作库提供了头文件atomic,
而线程支持库提供了头文件thread, mutex, condition_variable 和 future.

----------------------------------------------------------
18.7.2 新增的库
头文件random支持的可扩展随机数库提供了大量比 rand()复杂的随机数工具。
例如，你可以选择随机数生成器和分布状态，分布状态包括 均匀分布，二项式分布
和正态分布等。

头文件chrono提供了处理时间间隔的途径

头文件tuple支持模板tuple. tuple对象是广义的pair对象。
pair对象可存储两个类型不同的值，而tuple对象可存储任意多个
类型不同的值。

头文件ratio支持的编译阶段有理数算术库让你能够准确地表示任何有理数，
其分子和分母可用最宽地整型表示。它还支持对这些有理数进行算术运算。

在新增的库中，最有趣的一个是头文件regex支持的正则表达式库。
正则表达式指定了一种模式，可用于与文本字符串的内容匹配。
方括号表达式与方括号中的任何单个字符匹配，因此
[cCkK] 与 c、C、k和K都匹配。


----------------------------------------------------------
18.7.3 低级编程

另一项修改是，允许共用体的成员有构造函数和析构函数，
这让共用体更灵活；但保留了其他一些限制，如成员不能有虚函数。
在需要最大程度地减少占用的内存时，通常使用共用体。

C++解决了内存对齐问题。计算机系统可能对数据在内存中的存储方式有一定的限制。
可使用运算符alignof()

constexpr机制让编译器能够在编译阶段计算结果为常量的表达式，
让const变量可存储在只读内存中。

----------------------------------------------------------
18.7.4 杂项
C99引入了依赖于实现的扩展类型，C++11继承了这种传统。
在使用128位整数的系统中，可使用这样的类型。
在C语言中，扩展类型由头文件stdint.h支持，
而在C++中，为头文件cstdint

C++提供了调试工具assert。这是一个宏，它在运行阶段对断言进行检查，
如果为true，这显式一条消息，否则调用abort()。
C++11新增了关键字static_assert，可用于在编译阶段对断言进行测试。

C++11加强了对元编程 meta programming的支持。
元编程指的是编写这样的程序，它创建或修改其他程序，
甚至修改自身。在C++中，可使用模板在编译阶段完成这种工作。

----------------------------------------------------------
18.8 语言变化
18.8.1
Boost项目

18.8.2
TR1

18.8.3 使用Boost




