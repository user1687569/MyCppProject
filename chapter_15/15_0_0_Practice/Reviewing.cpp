//Copyright (c) 2022 user1687569


友元类的所有方法都可以访问原始类的私有成员和保护成员。
尽管友元类被授予从外部访问类的私有部分的权限，但他们并不与
面向对象的编程思想相悖；相反，它们提高了公有接口的灵活性。


共同的友元


异常何时会迷失方向？
异常被引发后，在两种情况下，会导致问题
1. 如果它是在带异常规范的函数中引发的，则必须与规范列表中的某种异常匹配
   在继承层次结构中，类类型与这个类及其派生类的对象匹配，否则称为意外异常 unexpected exception
2. 如果异常不是在函数中引发的，则必须捕获它。如果没被捕获，则异常被称为未捕获异常 uncaught exception


RTTI是Runtime Type Identification的简称，运行阶段类型识别
RTTI旨在为程序在运行阶段确定对象的类型提供一种标准方式


C++有3个支持RTTI的元素
1. 如果可能的话，dynamic_cast运算符将使用一个指向基类的指针来生成一个指向派生类的指针；
   否则，该运算符返回0 --- 空指针
2. typeid运算符返回一个指出对象的类型的值
3. type_info结构存储了有关特定类型的信息

只能将RTTI用于包含虚函数的类层次结构，原因在于只有对于这种类层次结构，才应该将派生对象的地址赋给基类指针
警告：RTTI只适合用于包含虚函数的类

1. dynamic_cast运算符
    它不能回答“指针指向的是哪类对象”这样的问题，
    但能够回答“是否可以安全地将对象地地址赋给特定类型的指针”这样的问题
2. typeid
   [提示]: 如果发现在扩展的 if else 语句系列中使用了 typeid, 则应考虑是否应该使用虚函数和 dynamic_cast
   Typeid运算符返回一个type_info对象，可以对两个typeid的返回值进行比较，
   以确定对象是否为特定的类型，而返回的type_info对象可用于获得关于对象的信息


C++更严格地限制允许的类型转换，并添加4个类型转换运算符，使转换过程更规范：
dynamic_cast   用途：使得能够在类层次结构中进行向上转换(由于is-a关系，这样的类型转换是安全的)，而不允许其他转换
const_cast     用途：改变值为 const 或 volatile
static_cast
reinterpret_cast  用于天生危险的类型转换


-----------------
[static_cast]
High是基类
Low 是 High的派生类
Pond是一个无关类
-----------------
High bar;
Low blow;
...
High * pb = static_cast<High *>(&blow);   // 合法，valid
Low * pl = static_cast<Low *>(&bar);      // 合法，valid
Pond * pmer = static_cast<Pond *>(&blow); // 不合法，invalid
-----------------
分析：
第一种转换是合法的，因为向上转换可以显式地进行
第二种转换是从基类指针到派生类指针，在不进行显式转换的情况下，将无法进行。
   但由于无需进行类型转换，便可以进行另一个方向的类型转换，
   因此使用static_cast来进行向下转换是合法的。
-----------------


同理，由于无需进行类型转换，可以使用static_cast将枚举值转换成整型


// 1
a. 友元声明如下:
   class snap {
      friend class clasp;
      ...
   };
   class clasp { ... };

b. 应该添加前向声明
   class muff;
   class cuff 
   {
   public:
      void snip(muff &) { ... }
      ...
   };
   class muff {
      friend void cuff::snip(muff &);
      ...
   };

c. 应cuff的类声明放在 muff类声明的前面，同时添加 muff类的前向声明
   因为编译器在muff类的声明中看到cuff的一个方法被声明为muff类的友元之前，
   应该先看到 cuff类的声明 和 snip()方法的声明
   #如上所示#


// 2 
能否创建相互类友元的方法，即类B只有部分成员是类A的友元，而类A只有部分成员是类B的友元？
请解释原因
答：不行。


// 3
下面的嵌套类声明中可能存在什么问题？
class Ribs
{
private:
   class Sauce
   {
      int soy;
      int sugar;
   public:
      Sauce(int s1, int s2) : soy(s1), sugar(s2) {} 
   };
};
答：访问类的唯一方法是通过其公有接口，这意味着对于Sauce对象，
   只能调用构造函数来创建一个。其他成员(soy 和 sugar)在默认情况下是私有的。


// 4
throw 和 return 之间的区别何在？
f1()
{
   f2();
}
答：假设函数f1()调用了函数 f2(). 
   f2()中的return语句导致程序执行在函数f1()中调用函数f2()后面的一条语句。
   throw语句导致程序沿函数调用的当前序列回溯，直到找到直接或间接
   包含对f2()的调用的try语句块为止。它可能在f1()中，调用f1()的函数中或其他函数中。
   找到这样的try语句块后，将执行下一个匹配的catch语句块，而不是函数调用后的语句。


// 5
假设有一个从异常基类派生来的异常类层次结构，
则应按什么样的顺序放置catch块？
答：应该按照从子孙到祖先的顺序放置catch语句块


// 6 下面两个代码示例的行为有什么不同
Grand
Superb
Magnificent
[pg 为 Grand * 指针]
[ps 为 Superb * 指针]
---------------------------------------
#Sample 1
if(ps = dynamic_cast<Superb *>(pg))
   ps->say();
对于示例#1，如果pg指向一个Superb对象或从Superb派生而来
的任何类的对象，则if条件为true。具体地说，如果pg指向
Magnificent对象，则if条件也为true.

---------------------------------------
#Sample 2
if(typeid(*pg) == typeid(Superb))
   (Superb *) pg->say(); 
对于示例2，仅当指向Superb对象时，if条件才为true,
如果指向的是从Superb派生出来的对象，则if条件不为true
---------------------------------------


// 7 static_cast 运算符 与 dynamic_cast运算符有什么不同？
dynamic_cast 运算符只允许沿类层次结构向上转换
而 static_cast 运算符允许向上转换和向下转换
static_cast 运算符还允许枚举类型和整型之间 以及 数值类型之间的转换

















